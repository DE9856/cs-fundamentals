//App.js

import {BrowserRouter, Route, Routes, Link} from 'react-router-dom';
import Prime from './prime';
import Cube from './cube';

function App() {
  return (<>
    <BrowserRouter>
      <Link to="/prime">Prime</Link>
      <Link to="/cube">Cube</Link>
      <Routes>
        <Route path="/prime" element={<Prime />}></Route>
        <Route path="/cube" element={<Cube />}></Route>
      </Routes>
    </BrowserRouter>
  </>)
}
export default App;



//Prime.js
function Prime(){
    function isPrime(n){
        for(let i=2;i<n;i++)
            if(n%i===0)
                return false;
        return true;
    }
    const findprime = () =>{
        const array = [];
        for(let i=2;i<100;i++)
            if(isPrime(i))
                array.push(i);
        return array;
    }

    return(<div>
        Prime Number under 100 are: <ul>{findprime().map((elem)=>{
            return(<li>{elem}</li>)})
        }</ul>
    </div>)
}
export default Prime;



//Cube.js
function Cube(){
    const findcube = () =>{
        const array = [];
        for(let i=0;i<5;i++){
            if((i*i*i)<100)
                array.push(i*i*i);
            else
                break;
        }
        return array;
    }

    return(<div>
        Cube Numbers under 100 are: <ul>{findcube().map((elem)=>{
            return(<li>{elem}</li>)})
        }</ul>
    </div>)
}
export default Cube;
