const fs = require("fs");
const path = require("path");
const dataDir = path.join(__dirname, "files");

if (!fs.existsSync(dataDir)) {
  fs.mkdirSync(dataDir);
}

function createFile(filename, data) {
  const filePath = path.join(dataDir, filename);

  fs.writeFile(filePath, data, (err) => {
    if (err) console.log(err);
    else console.log("File created");
  });
}

function readFile(filename) {
  const filePath = path.join(dataDir, filename);

  fs.readFile(filePath, "utf8", (err, data) => {
    if (err) console.log(err);
    else console.log("File content:", data);
  });
}

function updateFile(filename, newData) {
  const filePath = path.join(dataDir, filename);

  fs.writeFile(filePath, newData, (err) => {
    if (err) console.log(err);
    else console.log("File updated");
  });
}

function deleteFile(filename) {
  const filePath = path.join(dataDir, filename);

  fs.unlink(filePath, (err) => {
    if (err) console.log(err);
    else console.log("File deleted");
  });
}

createFile("sample.txt", "Hello World");
setTimeout(() => {
  readFile("sample.txt");

  setTimeout(() => {
    updateFile("sample.txt", "New Data");

    setTimeout(() => {
      readFile("sample.txt");

      setTimeout(() => {
        deleteFile("sample.txt");
      }, 500);

    }, 500);

  }, 500);

}, 500);
