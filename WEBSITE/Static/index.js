var slider = document.getElementById("myRange");
var output = document.getElementById("demo");
var newHumid = document.getElementById("newHumid");
/*
Takes the thing named "demo" or "myRange"
and stores it in variable
*/
output.innerHTML = slider.value;

slider.oninput = function() {
  output.innerHTML = this.value;
}