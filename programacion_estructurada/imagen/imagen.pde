String[] lines;      //define el arreglo para almacenar los datos
int index = 0;
void setup() {
  size(200, 200);
  background(0);
  stroke(255);
  frameRate(12);
  lines = loadStrings("positions.txt"); // carga el arreglo con los datos del archivo
  
  fill(120,34,120);

}
void draw() {
  int ncolor = 0;
  String letras;
  PFont font;
  font = loadFont("LilyUPCBoldItalic-100.vlw");
  if (index < lines.length) {     // evalua las filas del arreglo
    ncolor += 30;
    fill(204, 102, ncolor);
    letras = lines[index];
    for (int j=0; j<= letras.length()-1; j++){
        if (letras.charAt(j) == 'A'){
  
            fill(20,200,20);
        }
        if (lines[index].charAt(j) == '.'){
  
            fill(200,20,20);      
        }
        rect(10*j,index*10,10,10);
    }
      //  text(letras.charAt(j),10*j, index*20);
    index = index + 1;
  }
}


