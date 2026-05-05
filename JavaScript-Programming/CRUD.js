const fs = require('fs');
const path = require('path');
const datadir = path.join(__dirname, "files");

if(!fs.existsSync(datadir)){
    fs.mkdirSync(datadir);
}

function createfile(filename,data){
    const filepath = path.join(datadir,filename);
    fs.writeFile(filepath,data,(err)=>{
        if(err) console.log("Error in creating file");
        else console.log("Created file");
    });
}

function readfile(filename){
    const filepath = path.join(datadir,filename);
    fs.readFile(filepath,"utf8", (err,data)=>{
        if (err) console.log("Error in reading file");
        else console.log("Data read: ",data);
    });
}

function updatefile(filename,data){
    const filepath = path.join(datadir,filename);

    fs.writeFile(filepath,data,(err)=>{
        if(err) console.log("Error in updating file");
        else console.log("File Updated");
    });
}

function deletefile(filename){
    const filepath = path.join(datadir,filename);

    fs.unlink(filepath, (err)=>{
        if (err) console.log("Error in deleting file");
        else console.log("File Deleted Successfully");
    });
}

createfile("sample.txt", "Original Data");
setTimeout(()=>{
    readfile("sample.txt");
    setTimeout(()=>{
        updatefile("sample.txt", "Updated Data");
        setTimeout(()=>{
            readfile("sample.txt");
            setTimeout(()=>{
                deletefile("sample.txt");
            },500);
        },500);
    },500);
},500);
