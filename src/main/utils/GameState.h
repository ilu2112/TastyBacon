#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState {
    
    private:
        
        long long int state;

    public:
    
        static unsigned int rows;
        static unsigned int cols;
    
        GameState(long long int state);
        
        GameState(unsigned int ** array);
        
        static void setSize(unsigned int rows, 
                            unsigned int cols);     
                            
        static long long int getAsInt(unsigned int ** array);
                                      
        static unsigned int ** getAsArray(long long int state);
        
        static GameState * getFinalGameState();
        
        unsigned int ** getAsArray();
        
        long long int getAsInt();
        
        bool operator==(const GameState &gs) const;
        
        bool operator!=(const GameState &gs) const;
        
        bool operator>(const GameState &gs) const;
        
        bool operator<(const GameState &gs) const;
        
        bool operator<(const GameState * gs) const;
        
        
        struct Comparator {
            bool operator() (const GameState * lhs, 
                             const GameState * rhs) const;
        };

};

#endif
