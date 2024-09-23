let arr=[
    "ai.jpg",
    "dsa.jpg",
    "ml.jpeg",
    "os.jpg",
    "web.jpg"
];
document.getElementById("submit").addEventListener("click",function(){
    let index =Math.floor(Math.random()*arr.length);
    let image=document.getElementById("pic");
    image.src=arr[index];
    console.log("clickeed!");
})