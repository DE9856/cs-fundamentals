//Backend.js

const express = require('express')
const cors = require('cors')
const bodyParser = require('body-parser')
const mongoose = require('mongoose')
const { useTransition } = require('react')
mongoose.set('strictQuery', true)

main().catch(err=> console.log(err));
async function main(){
    await mongoose.connect('mongodb://127.0.0.1:27017/local');
    console.log('db connected')
}

const userSchema = new mongoose.Schema({
    usn: String,
    name: String,
    sem: Number,
    year: Number
});

const User = mongoose.model('studs', userSchema);

const server = express()
server.use(cors())
server.use(bodyParser.json())

server.post('/demo', async(req,res) =>{

    let user = new User()
    const keys = Object.keys(req.body);
    for(let i =0;i<keys.length;i++){
        user[keys[i]] = req.body[keys[i]]
    }
    const doc = await user.save();
    console.log('Input Data: ', doc);
    res.json(doc);
})

server.get('/data', async(req, res) => {
    const docs = await User.find({});
    res.json(docs)
})

server.listen(8000, () => {
    console.log('server started')
})  








//App.js Code
import './App.css';
import { useState, useEffect } from 'react'

function App(){
  const [form, setForm] = useState({})
  const [users, setUsers] = useState([])

  const handleForm = (e) => {
    setForm({
      ...form,
      [e.target.name]: e.target.value
    })
  }

  const handleSubmit = async (e) => {
    e.preventDefault();
    const response = await fetch('http://127.0.0.1:8000/demo',{
      method: 'POST',
      body: JSON.stringify(form),
      headers: {
        'Content-Type': 'application/json'
      }
    })
    const data = await response.json();
    console.log(data);
  }

  const getUsers = async () => {
    const response = await fetch('http://127.0.0.1:8000/data',{
      method: 'GET'
    });
    const data = await response.json();
    setUsers(data);
  }

  useEffect(() => {
    getUsers();
  },[users]);

  return (
    <div>
      <h2> Personal Details </h2>
      <form onSubmit = {handleSubmit} className = 'personal'>
        <span>USN : </span>
        <input type = 'text' name = 'usn' onChange={handleForm} /><br />
        <span>Name : </span>
        <input type = 'text' name = 'name' onChange={handleForm} /><br />
        <span>Sem : </span>
        <input type = 'number' name = 'sem' onChange={handleForm} /><br />
        <span>Year of Admission : </span>
        <input type = 'number' name = 'year' onChange={handleForm} /><br />

        <input type = 'submit' />
      </form>
      <div>
        <table>
          <tbody>
            {users.map((rows,k) =>{
              return (<tr key = {k}>
                <td>{rows.usn}</td>
                <td>{rows.name}</td>
                <td>{rows.sem}</td>
                <td>{rows.year}</td>
              </tr>)
            })}
          </tbody>
        </table>
      </div>
    </div>
  )
}
export default App;
