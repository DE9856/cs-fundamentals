import { useState } from 'react';

function App() {
  const initiallist = ['Mango', 'Banana', 'Samosa', 'Maggi', 'Bonda'];
  const [list, updatelist] = useState(initiallist);

  const filterlist = (event) => {
    const value = event.target.value.toLowerCase();

    if (value === "") {
      updatelist(initiallist);
      return;
    }

    const filtered = initiallist.filter(item =>
      item.toLowerCase().includes(value)
    );

    updatelist(filtered);
  };

  return (
    <div className="App">
      <label>Search: </label>
      <input type="text" onChange={filterlist} />
      <ul>
        {list.map((element) => (
          <li key={element}>{element}</li>
        ))}
      </ul>
    </div>
  );
}

export default App;
