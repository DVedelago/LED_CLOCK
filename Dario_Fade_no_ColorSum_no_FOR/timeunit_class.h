#define NUMPIXELS      60      //number of LED in the strip

class LedStripRunner
{
public:
  
  float intensity[NUMPIXELS];
  float SpeedUP;
  float SpeedDOWN;
  uint8_t red, green, blue;

//default white constructor 
  LedStripRunner(){
    
     SpeedUP=0.001;
     SpeedDOWN=0.003;
    
     for(int i=0; i<NUMPIXELS; i++)
     
        intensity[i]=0;

     setColor(255, 255, 255);
    }

  //custom speed&color constructor 
  LedStripRunner(float _SpeedUP, float _SpeedDOWN, uint8_t _red, uint8_t _green, uint8_t _blue){
    
    SpeedUP = _SpeedUP;
    SpeedDOWN = _SpeedDOWN;
    setColor(_red, _green, _blue);
    
    for(int i=0; i<NUMPIXELS; i++)
      intensity[i]=0;
    
  }
  
  //fading method: increase the intensity of a given pixel by a pre-set amount and 
  //once the pixel is not current anymore, decrease the intensity by a pre-set amount
  void UpdateIntensity(int currpixel)
  {
    
    for(int i=0; i<NUMPIXELS; i++){ 
      
      if(i==currpixel){
        
        if(intensity[i]<1)
          intensity[i]+=SpeedUP;
        
        else intensity[i]=1;
        
      }
      else 
      {
        if(intensity[i] > 0)
          intensity[i]-=SpeedDOWN;

        else intensity[i] =0;
      }
    }
  }
  
  //sets the RGB components for pixels.Color(...); in Adafruit's library
  void setColor(uint8_t _red, uint8_t _green, uint8_t _blue) {
    red = _red;
    green = _green;
    blue = _blue;
  }
  
};
