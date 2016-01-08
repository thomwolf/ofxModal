#include "ofApp.h"

void ofApp::setup()
{
    ofSetWindowPosition(ofGetScreenWidth()/2 - ofGetWidth()/2, 0);
    
// listen for events //
    confirm.onModalEvent(ofxModalEvent::SHOWN, this, &ofApp::onModalEvent);
    confirm.onModalEvent(ofxModalEvent::HIDDEN, this, &ofApp::onModalEvent);
    confirm.onModalEvent(ofxModalEvent::CANCEL, this, &ofApp::onModalEvent);
    confirm.onModalEvent(ofxModalEvent::CONFIRM, this, &ofApp::onModalEvent);

    confirm.setMessage("This is a confirm message. Stumptown street art photo booth try-hard cold-pressed, pour-over raw denim four loko vinyl. Banjo drinking vinegar tousled, Brooklyn Neutra meggings mlkshk freegan whatever.");
}

void ofApp::update() { }
void ofApp::draw() { }

void ofApp::keyPressed(int key)
{
    if (key == 'm'){
        confirm.show();
    }   else if (key == 'h'){
        confirm.hide();
    }
}

void ofApp::onModalEvent(ofxModalEvent e)
{
    if (e.type == ofxModalEvent::SHOWN){
        cout << "modal window is open" << endl;
    }   else if (e.type == ofxModalEvent::HIDDEN){
        cout << "modal window is closed" << endl;
    }   else if (e.type == ofxModalEvent::CANCEL){
        cout << "cancel button was selected" << endl;
    }   else if (e.type == ofxModalEvent::CONFIRM){
        cout << "confirm button was selected" << endl;
    }
}

