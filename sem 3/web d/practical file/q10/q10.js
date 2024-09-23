var btn=document.getElementById("btn");
var back=document.getElementById("back");

btn.addEventListener("click",function(){
    var xhr=new XMLHttpRequest();
    xhr.open('GET','q10.txt',true);
    xhr.onload=function(){
        document.getElementsByTagName("h1")[0].innerHTML=this.responseText;
    }
    xhr.send();
}
)

back.addEventListener("click",function(){
    document.getElementsByTagName("h1")[0].innerHTML="ques 10";
})