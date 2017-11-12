#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(90);
    myfont.load("FuturBTMed", 23);
    bigfont.load("FuturBTMed", 40);
    mode=0;
    
    ofSetFrameRate(50);
    start.load("Default-568h@2x~iphone.png");
    back.load("back1.png");
    back1.load("back.png");
    logo_min.load("logo_min.png");
    extend.load("extend.png");
    crap.load("clap.png");
    meter.load("meter.png");
    map.load("map.png");
    underbar.load("underbar.png");
    
    margin=ofGetWidth()/12;
    
    
    for(int i =0;i<6;i++){
            guiter[i].load("guiter"+ofToString(i)+".png");
    }
    bo.load("bo.png");
    bo1.load("bo1.png");
    R.load("R.png");
    L.load("L.png");
    tan[0].load("tan.png");
    tan[1].load("taico.png");
    tan[2].load("mara.png");
    
    count = 0;
    start_up = true;
    fade = 255;
    leftpos=150;
    rightpos = 700;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    center = ofPoint(ofGetWidth()/2,ofGetHeight()/2);
    count++;
    start.update();
    back.update();
    
    
    y = mouseY;
    zone = rightpos - leftpos;
    
    for(int i=0;i<2;i++){
        if(ring[i]){
            ban[i]+=0.25;
            if(ban[i]>1.0){
                ban[i]=0;
                ring[i]=false;
            }
        }
    }
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(start_up) {
        if(count<70){
            ofSetColor(255);
            start.draw(400,50 );
        }else if(70<=count){
            fade-=count/2;
            ofSetColor(255,fade);
            start.draw(400,50);
        }
        if(fade<0){
            count = 0;
            start_up=false;
            fade = 255;
            
        }
    }else if(start_up==false){
        
        if(mode==0){
            ofSetColor(255,255);
            
            threw -= 4;
            threw1 -= 4;
            if(threw == -1200){
                threw +=2400;
            }else if(threw1==-1200){
                threw1 += 2400;
            }
            
            ofSetColor(255);
            back.draw(threw,0,1200,ofGetHeight());
            back1.draw(threw1,0, 1200, ofGetHeight());
            
            ofDrawCircle(center.x-ofGetWidth()/4, center.y, 100);
            ofDrawCircle(center.x+ofGetWidth()/4, center.y, 100);
            
            ofSetColor(255,120);
            logo_min.draw(center.x - logo_min.getWidth()/2 , center.y - logo_min.getHeight()/2);
            
            ofSetColor(255);
            
            crap.draw(center.x-ofGetWidth()/4-crap.getWidth()/2,center.y-crap.getHeight()/2);
            
            extend.draw(center.x+ofGetWidth()/4-extend.getWidth()/2,center.y-extend.getHeight()/2);
        
        }
        if(mode==1){
            ofSetColor(255,255);
            
            threw -= 4;
            threw1 -= 4;
            if(threw == -1200){
                threw +=2400;
            }else if(threw1==-1200){
                threw1 += 2400;
            }
            
            ofSetColor(255);
            back.draw(threw,0,1200,ofGetHeight());
            back1.draw(threw1,0, 1200, ofGetHeight());
            
            int rond = ofRandom(-5,10);
            meter.draw(center.x-ofGetWidth()/4-130-rond/2,center.y-130-rond/2,260+rond,260+rond);
            meter.draw(center.x+ofGetWidth()/4-130-rond/2,center.y-130-rond/2,260+rond,260+rond);
            ofDrawCircle(center.x-ofGetWidth()/4, center.y, 100);
            ofDrawCircle(center.x+ofGetWidth()/4, center.y, 100);
            
            myfont.drawString("volume", center.x-ofGetWidth()/4-50, center.y+170);
            myfont.drawString("scale", center.x+ofGetWidth()/4-35, center.y+170);

            
            bigfont.drawString("Guiter", center.x-75, center.y+20);
            
            map.draw(0,70, ofGetWidth(), 70);
            ofSetColor(255,75);
            bo1.draw(0,ofGetHeight()-106, ofGetWidth(), 6);
            bo1.draw(0,ofGetHeight()-30, ofGetWidth(), 6);
            ofSetColor(255,120);
            logo_min.draw(center.x-20,20, 40, 32);
            
            ofSetColor(255);
            underbar.draw(leftpos,ofGetHeight()-100, rightpos-leftpos, 70);
            
            for(int i = 0; i<6;i++){
                if(A_choice==i){
                    ofSetColor(255);
                }else{
                    ofSetColor(255,75);
                }
                guiter[i].draw(margin*(2*i+1)-25,80, 50, 50);

            }
            ofSetColor(145, 193, 131);
            bigfont.drawString(ofToString((int)ofMap(y, 0, ofGetHeight(), 0, 100)), center.x/2-35, center.y+20);
            bigfont.drawString(ofToString((int)ofMap(zone, 0, ofGetWidth(), 0, 100)), ofGetWidth()*0.75-35, center.y+20);

            
            
        }
        if(mode==2){
            ofSetColor(255,255);
            
            threw -= 4;
            threw1 -= 4;
            if(threw == -1200){
                threw +=2400;
            }else if(threw1==-1200){
                threw1 += 2400;
            }
            
            ofSetColor(255);
            back.draw(threw,0,1200,ofGetHeight());
            back1.draw(threw1,0, 1200, ofGetHeight());
            
            map.draw(0,70, ofGetWidth(), 70);
            ofSetColor(255,75);
            bo.draw(center.x-3,140,6,ofGetHeight()-140);
            ofSetColor(255,120);
            logo_min.draw(center.x-20,20, 40, 32);

            for(int i = 0; i<3;i++){
                if(B_choice[0]==i){
                    ofSetColor(255);
                    tan[i].draw(center.x/2-75-15*sin(ban[0]),220-15*sin(ban[0]), 150+30*sin(ban[0]), 150+30*sin(ban[0]));
                    
                    if(i==0){
                        bigfont.drawString("Tambourine", center.x/2-140, 470);
                    }else if(i==1){
                        bigfont.drawString("Drum", center.x/2-76, 470);
                    }else if(i==2){
                        bigfont.drawString("Maracas", center.x/2-110, 470);
                    }
                    
                    
                }else{
                    ofSetColor(255,75);
                }

                tan[i].draw(margin*(2*i+1)-25,80, 50, 50);
                
            }
            for(int i = 0; i<3;i++){
                if(B_choice[1]==i){
                    ofSetColor(255);
                    tan[i].draw(ofGetWidth()*0.75-75-15*sin(ban[1]),220-15*sin(ban[1]), 150+30*sin(ban[1]), 150+30*sin(ban[1]));
                    
                    if(i==0){
                        bigfont.drawString("Tambourine", ofGetWidth()*0.75-140, 470);
                    }else if(i==1){
                        bigfont.drawString("Drum", ofGetWidth()*0.75-76, 470);
                    }else if(i==2){
                        bigfont.drawString("Maracas", ofGetWidth()*0.75-110, 470);
                    }

                    
                }else{
                    ofSetColor(255,75);
                }

                tan[i].draw(margin*(2*i+1)-25+center.x,80, 50, 50);
                
            }
            ofSetColor(255);
            L.draw(center.x/2-45,520, 80, 80);
            R.draw(ofGetWidth()*0.75-45,520, 80, 80);
            
            
            
            

        }
        
        
        
        
    }
    
    
    
    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='r'){
        ring[0]=true;
        ban[0]=0;
    }
    if(key=='l'){
        ring[1]=true;
        ban[1]=0;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
  
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
     if(slide_check[0]){
        if(rightpos>leftpos+10){
            leftpos = mouseX;
        }else{
            rightpos = leftpos + 12 ;
        }
    }
    if(slide_check[1]){
        if(rightpos>leftpos+10){
            rightpos = mouseX;
        }else{
            rightpos = leftpos + 12 ;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(mode==0){
        if(center.x-ofGetWidth()/4-80<mouseX&&mouseX<center.x-ofGetWidth()/4+80){
            mode=1;
            
        }else if(center.x+ofGetWidth()/4-80<mouseX&&mouseX<center.x+ofGetWidth()/4+80){
            mode=2;
        }
    }
    if(center.x-20<mouseX&&mouseX<center.x+20&&mouseY<50){
        mode=0;
    }
    
    if(mode==1){
        for(int i=0;i<6;i++){
            if(margin*2*i<mouseX&&mouseX<margin*2*(1+i)&&70<mouseY&&mouseY<140){
                A_choice = i;
            }
        }
       
        if(leftpos-10<mouseX&&mouseX<leftpos+10&&ofGetHeight()-100<mouseY&&mouseY<ofGetHeight()-30){
            slide_check[0] = true;
        }

        if(rightpos-10<mouseX&&mouseX<rightpos+10&&ofGetHeight()-100<mouseY&&mouseY<ofGetHeight()-30){
            slide_check[1] = true;
        }

        
    }
    if(mode==2){
        for(int i=0;i<3;i++){
            if(margin*2*i<mouseX&&mouseX<margin*2*(1+i)&&70<mouseY&&mouseY<140){
                B_choice[0] = i;
            }
            if(margin*2*i+center.x<mouseX&&mouseX<margin*2*(1+i)+center.x&&70<mouseY&&mouseY<140){
                B_choice[1] = i;
            }
        }

    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    for(int i=0;i<2;i++){
        slide_check[i] = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY ) {
    // ここに、スクロール時の処理を実装します。
    cout << "mouse scrolled: (" << scrollX << "," << scrollY << ")" << endl;
}
