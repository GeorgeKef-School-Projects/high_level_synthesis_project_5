#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ac_int.h"


typedef ac_int<1,false> edge;

static const int M = 6;


class graph_color{
  private:
  public:
    graph_color(){};
    
    void run(edge adj_g[M][M], short num_of_cols, short col_of_vertex[M]){
      //Set the colors of each vertex to 0; 
      for(int i = 1;i < M;i++){
        col_of_vertex[i] = 0;
      }
      //Set the value of number of colors to one. 
      num_of_cols = 1;
      std::cout << "num_of_cols:" << num_of_cols << std::endl;

      //The first loop is to check all the vertexes
      //Then we set the color of the vetrex to one
      //If thw next loop finds a vetrex that is adjasted 
      //to our current vertex and the colors of wich exists 
      //go to the next color. 
      //If this color is greater than the num of colors change it. 
      for(int i = 0;i < M;i++){
        col_of_vertex[i] = 1;
        for(int j = 0;j < M;j++){
	  if((j != i) && (adj_g[i][j] == 1) && (col_of_vertex[i] == col_of_vertex[j])){
	    
	    col_of_vertex[i]++;
	  
	  }
 
	  if(col_of_vertex[i] > num_of_cols){
	    num_of_cols = col_of_vertex[i];
            std::cout << "num_of_cols:" << num_of_cols << std::endl;
	  }
	}
      }
    }

};


int main(){

  graph_color G;

  edge adj_g[M][M];
  short c; 
  short c_vertex[M];

  std::srand(std::time(NULL));
  
  //Fill the adj matrix with random vals.
  for(int i = 0;i < M;i++){
    for(int j = i;j < M;j++){
      if(i == j){
        adj_g[i][j] = 0;
      }else{
	adj_g[i][j] = rand();
        adj_g[j][i] = adj_g[i][j];
      }
      std::cout << "The number in pos(i,j):" << i << "," << j << " is:" << adj_g[i][j] << std::endl; 
      std::cout << "The number in pos(j,i):" << j << "," << i << " is:" << adj_g[j][i] << std::endl; 
    }
  }

  //Call the function graph_color
  G.run(adj_g,c,c_vertex);

  //Print results
  std::cout << "The number of colors that we need:" << c << std::endl;

  for(int i = 0;i < M;i++){
    std::cout << "The color of vertex:" << i << ", is:" << c_vertex[i] << std::endl;
  }

  return 0;


}




