//Backend.js
const express = require('express');
const cors = require('cors');
const bodyParser = require('body-parser');
const mongoose = require('mongoose');
mongoose.set('strictQuery', true);

main().catch(err => console.log(err));
async function main() {
    await mongoose.connect('mongodb://127.0.0.1:27017/local');
    console.log('db connected')
}

const userSchema = new mongoose.Schema({
    uname: String,
    pass: String
});

const User = mongoose.model('users', userSchema);
const server = express();
server.use(cors());
server.use(bodyParser.json());

server.post('/demo', async (req, res) => {
    const username = req.body.uname, password = req.body.pass;
    const docs = await User.findOne({ username });
    if (docs) {
        if (docs.pass === password) {
            res.json("Login Success");
        } else {
            res.json("Invalid UserName or Password")
        }
    }
})

server.listen(8080, () => {
    console.log('server started')
})



//App.js
import './App.css';
import { useState } from 'react';
import axios from 'axios';

function App() {
  const [form, setForm] = useState({});
  const handleForm = (e) => {
    setForm({
      ...form,
      [e.target.name]: e.target.value
    })
  }

  const handleSubmit = async (e) => {
    e.preventDefault();
    const response = await axios('http://127.0.0.1:8080/demo', {
      method: 'POST',
      data: JSON.stringify(form),
      headers: {
        'Content-Type': 'application/json'
      }
    })
    const data = await response.data;
    window.alert(data);
  }

  return (
    <div>
      <h2>Personal Details</h2>
      <form onSubmit={handleSubmit} className='personal'>
        <span>User Name : </span>
        <input type='text' name='uname' onChange={handleForm} /><br />
        <span>Password : </span>
        <input type='password' name='pass' onChange={handleForm} /><br />
        <input type='submit' />
      </form>
    </div>
  )
}

export default App;
