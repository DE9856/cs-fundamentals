//App.js

import {BrowserRouter, Route, Routes, Link} from 'react-router-dom';
import Prime from './prime';
import Cube from './cube';

function App() {
  return (<>
    <BrowserRouter>
      <Link to="/prime">Prime</Link>&nbsp;&nbsp;
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
        for (let i = 2; i < n; i++) {
            if(n % i === 0)
                return false;
        }
        return true;
    }
    const findPrime = () => {
        const array = [];
        for (let i = 2; i <= 100; i++) {
            if (isPrime(i))
                array.push(i);
        }
        return array;
    };
    return (<div>
        Primes less than 100 are <ul>{findPrime().map((elem) => { return(<li>{elem}</li>) })}</ul>
    </div>)
}
export default Prime;



//Cube.js
function Cube() {
    const findCube = () => {
        const array = [];
        for (let i = 1; i < 100; i++) {
            if ((i * i * i) < 100)
                array.push(i * i * i);
            else
                break;
        }
        return array;
    };
    return (<div>
        Cubes less than 100 are <ul>{findCube().map((elem) => { return(<li>{elem}</li>) })}</ul>
    </div>)
}
export default Cube;
