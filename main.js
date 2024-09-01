function promisifiedTimeout(duration){
    let p=new Promise(function(resolve){
        setTimeout(resolve,duration);
    });
    return p;
}

let a=promisifiedTimeout(1000);
a.then(function(){
    console.log("hellow");
});