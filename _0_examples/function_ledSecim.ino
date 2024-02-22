
// parametrede verilen pine 1 diğerlerine 0 verir
void ledSecim(int pin){
  for(int i=8;i<=11;i++){
    digitalWrite(i,(i==pin));
  }
}
