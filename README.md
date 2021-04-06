# Tic-Tac-Toe Bot

Hey ! Welcome. 

It's a Tic-Tac-Toe game which developed for fun back in High-School.
Afterwards, I improvised it further by adding a computer bot that you can play with different levels of difficulties.


I used 2 different kinds of algorithm for creating different levels of difficulty.

For the impossible level , I implemented Mini-Max algorithm (using Decision-Tree from scratch) and optimized it with alpha-beta pruning.

For normal and hard levels, I deployed my own algorithm which after observing and playing numerous times against other algorithms to understand how actually they function, I also developed a algorithm that allows the computer to play with different difficulty levels.

The algorithm is based on the following scenarios:

1) The Game is in the initial phase (i.e only 1-2 moves have been made). Here the algorithm randomly places the element at any vacant space (if the game is been played in hard difficulty, the algorithm will trying placing the first element at the centre position to avoid being tricked over)

2) Once the game is in the middle phase (i.e moves 3-7), the algorithm will do the following based on decreasing priority
   
   (i) Will check if there is a winning situation such that it can win the game in the very move itself. If so, it will try to                    implement it by placing a element in that position and eventually winning the game.
    
   (ii) Will check if there is a winning situation for the opponent such that the opponent can win the game in the very next                       move itself. If so, it will try to prevent it by placing a element in that position the opponent would place.
   
   (iii) If the above 2 cases fail, it will try to create a winning possibility by extending the line in which there's                              already a element of it present and the line has the potential to hold 3 same elements. 
   
3) If the above scenarios fails means the game is in the ending phase (i.e moves 7-8), here the algorithm will just play the      game till a draw.   
