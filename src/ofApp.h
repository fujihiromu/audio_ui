#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void mouseScrolled(int x, int y, float scrollX, float scrollY );
    
    ofImage start,back,back1,logo_min,extend,crap,meter,map,underbar,guiter[6],bo,bo1,R,L,tan[3];
    
    int count;
    bool count_up;
    int back_position;
    bool start_up;
    int fade;
    int mode;
    
    int threw1 = 1200;
    int threw=0;
    ofVec2f center;
    
    ofTrueTypeFont myfont,bigfont;
    
    
    int margin;
    
    int A_choice;
    int B_choice[2];
    
    int y;
    int zone;
    int rightpos;
    int leftpos;
    
    bool slide_check[2];
    bool ring[2];
    float ban[2];
    
    
};
