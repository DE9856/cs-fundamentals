const express = require('express');
const cookieParser = require('cookie-parser');
const app = express()
app.use(cookieParser());

app.get('/setcookie', function(req, res){
    res.cookie("My_Cookie", "Welcome to MERN");
    res.send("Coookie successfully Added");
})

app.get('/getcookie', function(req, res){
    res.send(req.cookies)
})

app.listen(3000, (err)=> {
    if (err) throw err;
    console.log("Server running on port 3000");
})
