#include"FibLFSR.h"
//#include<Image.hpp>
//#include<Color.hpp>

int main(int argc, char* argv[])
{
  //read the command lines arguments
  if(argc == 1 || argc == 2 || argc == 3 || argc > 4)
    {
      cerr << "Error: Must have 3 command line arguments" << endl;
      return -1;
    }
    
   std::string commLineOne = argv[1];//input
   std::string commLineTwo = argv[2];//output
   std::string commLineThree = argv[3];//seed
    
  FibLFSR lsfrSeed(commLineThree); //change seed to lfsr type

 sf::Image imageInput;
 if(!imageInput.loadFromFile(commLineOne))// get input image
   {
     return -1;
   }
 sf::Vector2u size = imageInput.getSize();
 sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Source File");
 sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output Image");

 sf::Image imageOutput = imageInput;
 transform(imageOutput, &lsfrSeed);
 imageOutput.saveToFile(commLineTwo);

 sf::Texture photoTexture;
 if(!photoTexture.loadFromFile(commLineOne))
   {
     return -1;
   }
 sf::Sprite sprite(photoTexture);
 sf::Texture photoTextureTwo;
 if(!photoTextureTwo.loadFromFile(commLineTwo))
   {
     return -1;
   }
 sf::Sprite spriteTwo(photoTextureTwo);
while (window1.isOpen() && window2.isOpen())
 {
     sf::Event event;
     while (window1.pollEvent(event))
       {
     if (event.type == sf::Event::Closed)
     window1.close();
       }
 while (window2.pollEvent(event))
 {
 if (event.type == sf::Event::Closed)
 window2.close();
 }
 window1.clear();
 window1.draw(sprite);
 window1.display();
 window2.clear();
 window2.draw(spriteTwo);
 window2.display();
 }
  return 0;
}
void transform( sf::Image& image, FibLFSR* lfsr)
{
  sf::Color p;
  sf::Vector2u size = image.getSize();//get unsigned int image size
  for (unsigned int x = 0; x < size.x; x++)//x-axis size
    {
      for (unsigned int y = 0; y < size.y; y++)//y-axis size
	{
	  p = image.getPixel(x, y);
	  p.r = p.r ^ lfsr->generate(8); //XOR red component by newly generated seed
	  p.g = p.g ^ lfsr->generate(8); //XOR green component by newly generated seed
	  p.b = p.b ^ lfsr->generate(8); //XOR blue component by newly generated seed
	  image.setPixel(x, y, p); //set the pixels with a new color
	}
    }
}
