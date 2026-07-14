import {useState} from 'react';

function App(){
  const initiallist = ['Mango', "Maggi", 'Banana', "Watermelon", "Apple"];
  const [list,updatelist] = useState(initiallist);

  const filterlist = (event) =>{
    const filtered = [];
    if(event.target){
      for(let i =0;i<initiallist.length;i++){
        if(initiallist[i].toLowerCase().includes(event.target.value.toLowerCase()))
          filtered.push(initiallist[i]);
      }
      updatelist(filtered);
    }
    else{
      updatelist(initiallist);
    }
  };

  return (
    <div className = "App">
      <label>Search: </label>
      <input type = 'text' onChange = {filterlist} />
      <ul>
        {list.map((element)=>(
          <li key = {element}>{element}</li>
        ))}
      </ul>
    </div>
  )
}
export default App;
