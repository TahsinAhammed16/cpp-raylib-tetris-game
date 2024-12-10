#include "colors.h"

const Color darkGrey = {30, 35, 45, 255};  
const Color green = {50, 240, 40, 255};    
const Color red = {255, 30, 30, 255};      
const Color orange = {240, 130, 30, 255}; 
const Color yellow = {250, 240, 30, 255};  
const Color purple = {180, 10, 255, 255};  
const Color cyan = {30, 220, 225, 255};    
const Color blue =  {100, 150, 255, 255};     
const Color lightBlue = {70, 100, 180, 255}; 
const Color darkBlue = {50, 50, 150, 255};  


vector<Color> GetCellColors()
{
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue, lightBlue, darkBlue};
}