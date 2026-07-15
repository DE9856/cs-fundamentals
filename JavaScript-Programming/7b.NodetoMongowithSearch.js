//backend.js
const express = require('express');
const cors = require('cors');
const bodyParser = require('body-parser');
const mongoose = require('mongoose');
mongoose.set('strictQuery', true);

main().catch(err=>console.log(err));

async function main(){
    await mongoose.connect('mongodb://127.0.0.1:27017/local');
    console.log('db connected');
}

const userSchema = new mongoose.Schema({
    usn: String,
    name: String,
    sem: Number,
    year: Number
});

const User = mongoose.model('studs', userSchema);
const server = express();
server.use(cors());
server.use(bodyParser.json());

server.post('/demo', async(req,res)=>{
    const user = new User();
    const keys = Object.keys(req.body);
    for(let i=0;i<keys.length;i++)
        user[keys[i]] = req.body[keys[i]];
    const doc = await user.save();
    console.log('Input: ', doc);
    res.json(doc);
});

server.get('/data', async(req,res)=>{
    const docs = await User.find({});
    res.json(docs);
})

server.get('/search/:name', async(req,res)=>{
    const docs = await User.find({
        name: {
            $regex: req.params.name,
            $options: 'i'
        }
    });
    res.json(docs);
});

server.listen(8080, ()=>{
    console.log("server started");
})






//App.js
import {useState, useEffect} from 'react';

function App(){
  const [form, setForm] = useState({});
  const [users, setUsers] = useState([]);
  const [search, setSearch] = useState("");

  const handleform = (e) =>{
    setForm({
      ...form,
      [e.target.name]:e.target.value
    })
  }

  const handlesubmit = async(e) =>{
    e.preventDefault();
    const response = await fetch('http://127.0.0.1:8080/demo', {
      method: 'POST', 
      body: JSON.stringify(form),
      headers: {
        'Content-Type':'application/json'
      }
    })
    const data = await response.json();
    console.log(data);

    getUsers();
  }


  const getUsers = async()=>{
    const response = await fetch('http://127.0.0.1:8080/data', {
      method: 'GET'
    })
    const data = await response.json();
    setUsers(data);
  }

  const searchUsers = async(e)=>{
    const value = e.target.value;
    setSearch(value);
    if(value===''){
      getUsers();
      return;
    }
    const response = await fetch(`http://127.0.0.1:8080/search/${value}`);
    const data = await response.json();
    setUsers(data);

  }

  useEffect(()=>{
    getUsers()
  },[]);



  return(<div>
    <h2>Student Information</h2>
    <form onSubmit={handlesubmit} className='personal'>
      <span>USN: </span>
      <input type='text' name='usn' onChange={handleform} /><br />
      <span>Name: </span>
      <input type='text' name='name' onChange={handleform} /><br />
      <span>Sem: </span>
      <input type='number' name='sem' onChange={handleform} /><br />
      <span>Year: </span>
      <input type='number' name='year' onChange={handleform} /><br />
      <input type='submit' />
    </form>
    <label>Search: </label>
    <input type='text' value={search} onChange={searchUsers} placeholder='Enter Partial Name' /><br />
    <div>
      <table>
        <tbody>
          {users.map((rows,k)=>{
            return(<tr key={k}>
              <td>{rows.usn}</td>
              <td>{rows.name}</td>
              <td>{rows.sem}</td>
              <td>{rows.year}</td>
            </tr>);
          })}
        </tbody>
      </table>
    </div>
  </div>);

};
export default App;
