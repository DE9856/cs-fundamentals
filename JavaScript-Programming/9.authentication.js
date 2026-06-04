//Backend.js
const express = require('express');
const cors = require('cors');
const bodyparser = require('body-parser');
const mongoose = require('mongoose');
mongoose.set('strictQuery',true);

main().catch(err=>console.log(err));
async function main(){
    await mongoose.connect('mongodb://127.0.0.1:27017/local');
    console.log('db connected');
}

const UserSchema = new mongoose.Schema({
    uname: String,
    pass: String
})

const User = mongoose.model('users',UserSchema);
const server = express();
server.use(cors());
server.use(bodyparser.json());

server.post('/demo',async(req,res)=>{
    const username = req.body.uname;
    const password = req.body.pass;
    const docs = await User.findOne({uname:username});
    if(docs){
        if(docs.uname===username && docs.pass===password)
            res.json("Login Success");
        else
            res.json("Login Failed");
    }
    else{
        res.json("Username not Found");
    }
})

server.listen(8000,()=>{
    console.log("Server started on port 8000");
})

//App.js
import {useState} from 'react';
import axios from  'axios';

function App(){
    const [form,setForm] = useState({});
    const handleForm = (e) => {
        setForm({
            ...form,
            [e.target.name] : e.target.value
        })
    }

    const handleSubmit = async(e) =>{
        e.preventDefault();
        const response = await axios('http://localhost:8000/demo',{
            method: 'POST',
            data: JSON.stringify(form),
            headers : {'Content-Type':'application/json'}
        })
        const data = await response.data;
        window.alert(data);
    }

    return(
        <div>
            <h2>Personal Details</h2>
            <form onSubmit = {handleSubmit}>
                <span>Username: </span>
                <input type='text' onChange = {handleForm} name='uname' /><br />
                <span>Password: </span>
                <input type='text' onChange = {handleForm} name='pass' /><br />
                <input type = 'submit' />
            </form>
        </div>
    );
}
export default App;
