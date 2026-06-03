import React, { useState, useEffect } from 'react';

const App = () => {
  const [data, setData] = useState([]);

  useEffect(() => {
    fetch('https://jsonplaceholder.typicode.com/users')
      .then(res => res.json())
      .then(setData);
  }, []);

  return (
    <div>
      <h2>User Data</h2>
      <table border="1">
        <thead>
          <tr><th>Name</th><th>Email</th></tr>
        </thead>
        <tbody>
          {data.map(({ id, name, email }) => (
            <tr key={id}>
              <td>{name}</td><td>{email}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
};

export default App;
