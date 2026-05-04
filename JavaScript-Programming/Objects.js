const car = {
    brand: "Hyundai",
    model: "Creta",
    year: 2021,
    colour: "Maroon"
};

console.log("Original Properties: ");
for(let key in car){
    console.log(`${key}: ${car[key]}`);
}
console.log(Object.keys(car));
const secondproperty = Object.keys(car)[1];
delete car[secondproperty];

console.log("Properties after Deletion: ");
for(let key in car){
    console.log(`${key}: ${car[key]}`);
}
console.log(Object.keys(car));
const length = Object.keys(car).length;
console.log('\nLength of Object: ',length);
