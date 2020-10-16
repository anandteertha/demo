let runningTotal = 0;
let buffer ="0";
let previousOperator ;

const screen= document.querySelector(".screen");

function onClick(val){
    if(isNaN(val)){
        handleSymbol(val);
    }
    else{
        handleNumber(val);
    }
}

function handleNumber(numString){
    if (buffer === "0"){
        buffer = numString;
    }
    else{
        buffer += numString;
    }
    console.log(buffer)
    screen.innerText = buffer;
}

function init()
{
    document.querySelector(
        ".calc-buttons").addEventListener("click",function(event){
        onClick(event.target.innerText);
    })
}

init();