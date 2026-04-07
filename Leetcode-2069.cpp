/*
 * Problem 2069: Walking Robot Simulation II (POTD)
 * Language: C++
 */
class Robot {
    int w, h;
    int pos;
    int perimeter;
    bool moved;  
public:
    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w - 1) + 2 * (h - 1);
        pos = 0;
        moved = false;
    }
    
    void step(int num) {
        pos = (pos + num) % perimeter;
        moved = true; 
    }
    
    vector<int> getPos() {
        if (pos <= w - 1) return {pos, 0};
        else if (pos <= (w - 1) + (h - 1)) return {w - 1, pos - (w - 1)};
        
        else if (pos <= 2 * (w - 1) + (h - 1)) return {(w - 1) - (pos - ((w - 1) + (h - 1))), h - 1};
        else return {0, (h - 1) - (pos - (2 * (w - 1) + (h - 1)))};     
    }
    
    string getDir() {
        if (pos == 0) return moved ? "South" : "East";
        
        if (pos <= w - 1) return "East";
        if (pos <= (w - 1) + (h - 1)) return "North";
        if (pos <= 2 * (w - 1) + (h - 1)) return "West";
        return "South";
    }
};