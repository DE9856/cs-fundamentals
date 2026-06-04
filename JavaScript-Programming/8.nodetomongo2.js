//Backend.js

const express = require('express');
const cors = require('cors');
const bodyParser = require('body-parser');
const mongoose = require('mongoose');
mongoose.set('strictQuery',true);

main().catch(err=> console.log(err));

async function main(){
    await mongoose.connect('mongodb://127.0.0.1:27017/local');
    console.log('db connected')
}

const userSchema = new mongoose.Schema({
    fname: String,
    price: Number
});

const User = mongoose.model('fruits',userSchema);
const server = express();

server.use(cors());
server.use(bodyParser.json());

server.post('/demo', async(req,res)=>{
    let user = new User();
    const keys = Object.keys(req.body);
    for(let i = 0;i<keys.length;i++){
        user[keys[i]] = req.body[keys[i]]
    }
    const doc = await user.save()
    console.log('Input Data: ', doc);
    res.json(doc);
})

server.get('/data', async (req, res)=>{
    const docs = await User.find({});
    res.json(docs);
})

server.listen(8080,()=>{
    console.log("Server Started");
})






/App.js

import './App.css';
import { useState, useEffect } from 'react';
import axios from 'axios'

function App() {
  const [form ,setForm] = useState({})
  const [users, setUsers] = useState([])
  const handleForm = (e) => {
    setForm({
          ...form,
          [e.target.name]: e.target.value
    })
  }

  const handleSubmit = async (e) => {
    e.preventDefault();
    const response = await axios('http://127.0.0.1:8080/demo',{
      method: 'POST',
      data: JSON.stringify(form),
      headers: {
        'Content-Type': 'application/json'
      }
    })
    const data = await response.data;
    console.log(data);
  }

  const getUsers = async () =>{
    const response = await axios('http://127.0.0.1:8080/data',{
      method: 'GET',
    });
    const data = await response.data;
    setUsers(data);
  }

  useEffect(() =>{
    getUsers();
  }, [users]);
  return (
    <div>
      <h2>Personal Details</h2>
      <form onSubmit={handleSubmit} className='personal'>
        <span>Fruit Name : </span>
        <input type='text' name='fname' onChange={handleForm} /><br />
        <span>Price : </span>
        <input type='number' name='price' onChange={handleForm} /><br></br>
        <input type = 'submit' />
      </form>
      <div>
        <table>
          <tbody>
            {users.map((rows,k)=> {
              return (<tr key={k}>
                <td>{rows.fname}</td>
                <td>{rows.price}</td>
              </tr>)
            })}
          </tbody>
        </table>  
      </div>
    </div>
  )
}

export default App;
