#pragma once

#include "ofMain.h"
#include "ofxKinectV2.h"
#include "ofxGui.h"
#include "ofxCv.h"
#include "ParticleSystem.h"

using namespace std;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
  
    // Application GUI.
    ofxPanel gui;
  
    // Kinect Gui group.
    ofxGuiGroup kinectGroup;
  
    // Kinect.
    ofxKinectV2 * kinect;
    ofTexture texDepth;
    ofTexture texRGB;
  
    // Contour Finder.
    ofxCv::ContourFinder contourFinder;
  
    // OpenCV UI parameters. 
    ofxGuiGroup cvGroup;
    ofxFloatSlider minArea, maxArea, threshold;
  
    // Particle System
    ParticleSystem particleSystem;
};
