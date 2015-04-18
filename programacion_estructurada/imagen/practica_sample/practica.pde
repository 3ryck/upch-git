/**
* @author erick.alvarado.ez@outlook.com<eryck.3ryck.ryck>
* v1.0 19022015
*/

/*Imports*/
  import java.util.Random;
  import java.util.HashMap;
/*END Imports*/

/*Global Variables*/
  String lines[],      //define el arreglo para almacenar los datos
    tkns;
  int index = 0,
    N_COLORS = 16,
    COLOR_RATIO = 20, /*Decrease it in order to get smooth-darker-colors*/
    BG_COLOR = 255,
    c_ran,
    x_pxsize = 20,
    y_pxsize = 20,
    stageWidth, /*Stage size(width, height) is set depending on string.length*/
    stageHeight,
    deault_stageSize = 200; /*Default stage size*/
  final char _CIRCLE = 'A',
    _TRIANGLE = 'C';
  Integer[][] Colors;
  Random rand;
  HashMap<Character, Integer[]> Color;
/*END Global Variables*/

void setup() {
  tkns = "ABCDEFGHIJKLMNOP"; /*16 Simbolos*/
  Color = new HashMap();
  Colors = new Integer[N_COLORS][];
  rand = new Random();
  lines = loadStrings("fig.txt"); // carga el arreglo con los datos del archivo
  stageWidth = lines.length * x_pxsize;
  stageHeight = lines.length * y_pxsize;
  if(stageWidth < deault_stageSize)
    stageWidth = deault_stageSize;
  if(stageHeight < deault_stageSize)
    stageHeight = deault_stageSize;
  size(stageWidth, stageHeight);
  background(BG_COLOR);
  stroke(255, 50);
  frameRate(12);
  setColors(true);
  fill(120,34,120);
}

void draw() {
  int ncolor = 0;
  String letras;
  PFont font;
  //font = loadFont("LilyUPCBoldItalic-100.vlw");
  if (index < lines.length) {     // evalua las filas del arreglo
    c_ran = rand.nextInt(N_COLORS);
    //ncolor += 30;
    //fill(204, 102, ncolor);
    fill(Colors[c_ran][0], Colors[c_ran][1], Colors[c_ran][2]);
    letras = lines[index];
    char l;
    for (int j=0; j<= letras.length()-1; j++){
        l = letras.charAt(j);
        if (isTkn(l)){
            //fill(20,200,20);
            fill(((Integer[])Color.get(l))[0], 
            ((Integer[])Color.get(l))[1], 
            ((Integer[])Color.get(l))[2]);
            
            switch(l){
             case _CIRCLE: /*CIRCLE*/
               ellipse(x_pxsize*j,index*y_pxsize,x_pxsize,y_pxsize);
              break;
             case _TRIANGLE: /*TRIANGLE*/
               //triangle((x_pxsize/2 )*(j+1),index*y_pxsize, x_pxsize*(j+1), (index+1)*y_pxsize, ((x_pxsize*(j+1)) - x_pxsize),((1+index)*y_pxsize));
               triangle(((x_pxsize*(j+1)) - x_pxsize),((1+index)*y_pxsize), 
               (x_pxsize/2 )*(j+1),index*y_pxsize, x_pxsize*(j+1), (index+1)*y_pxsize);
              break;
             default: /*SQUARE*/
              rect(x_pxsize*j,index*y_pxsize,x_pxsize,y_pxsize);
            }
        }
        //rect(x_pxsize*j,index*y_pxsize,x_pxsize,y_pxsize);
    }
      //  text(letras.charAt(j),10*j, index*20);
    index = index + 1;
  }
}

void setColors(boolean random){
    if(random)
      randomColors();
//    else{
//       for(int i = 0; i < 16; i++) // R:RED B:BLUE b:brown O:ORANGE Y:YELLOW
//          Colors[i] = new int[3];         //G:GREEN g:GRAY C:CYAN M:MAGENTA S:SILVER
//                                          //P:PURPLE p:PINK V:VIOLET D:BLACK T:TEAL c:CRIMSON
//        
//    }                                       
}

void randomColors(){
   int rgb[] = {0, 0, 0};
  int c_ratio = COLOR_RATIO;
  int r;
  Random ran = new Random();
  for(int i = 0; (i < N_COLORS) && (i < tkns.length()); i++){
   r = ran.nextInt(3); /*1*/
   rgb[r] += c_ratio;
   if(rgb[r] > 255){
     rgb[r] = 0;
   }
   r = ran.nextInt(3); /*2*/
   rgb[r] += c_ratio;
   if(rgb[r] > 255){
     rgb[r] = 0;
   }
   r = ran.nextInt(3); /*3*/
   rgb[r] += c_ratio;
   if(rgb[r] > 255){
     rgb[r] = 0;
   }
     
   Colors[i] = new Integer[3];
   Colors[i][0] = rgb[0];
   Colors[i][1] = rgb[1];
   Colors[i][2] = rgb[2];
   Color.put(tkns.charAt(i), Colors[i]);
  }
  /*for(int i = 0; i < N_COLORS; i++)
    println("\ncolor[ " + i + "]: " + Colors[i][0] + " " + Colors[i][1] + " " + Colors[i][2]);*/ 
}

boolean isTkn(char c){
 int len = tkns.length();
 for(int i = 0; i < len; i++){
  if(c == tkns.charAt(i))
    return true;
 }
 return false;
}
