/*
 *  midiFighter.cpp
 *  InputExample
 *
 *  Created by Joshua Batty on 5/08/12.
 *  Copyright 2012 Buffer Music Production. All rights reserved.
 *
 */

#include "korg.h"

//--------------------------------------------------------------
void Korg::setup() {

	// print input ports to console
	midiIn.listPorts(); // via instance
	midiOut.listPorts(); // via instance
		//ofxMidiIn::listPorts(); // via static as well
	
	// open port by number (you may need to change this)
	midiIn.openPort(0);
	midiOut.openPort(0);	// by number
		//midiIn.openPort("IAC Pure Data In");	// by name
	//midiIn.openVirtualPort("ofxMidiIn Input");	// open a virtual port
	
	// don't ignore sysex, timing, & active sense messages,
	// these are ignored by default
	midiIn.ignoreTypes(false, false, false);
	
	// add midiFighter as a listener
	midiIn.addListener(this);
	
	// print received messages to the console
	midiIn.setVerbose(true);
	
	channel = 1;
	note = 0;
	velocity = 0;
	
	i = 0;

	//Init toggles
	for(int i = 0; i < 8; i++){
		buttonsSolo[i]=false;
		buttonsMute[i]=false;
		buttonsRec[i]=false;
	}
 
}

//--------------------------------------------------------------
void Korg::update() {
	
	NoteOnOff = ofxMidiMessage::getStatusString(midiMessage.status);
	
    ////////////////////////////////////
	//			SLIDERS				  //
	////////////////////////////////////
	
	if(midiMessage.control == 0){
		sliders[0] = midiMessage.value;
	}
	if(midiMessage.control == 1){
		sliders[1] = midiMessage.value;
	}
	if(midiMessage.control == 2){
		sliders[2] = midiMessage.value;
	}
	if(midiMessage.control == 3){
		sliders[3] = midiMessage.value;
	}
	if(midiMessage.control == 4){
		sliders[4] = midiMessage.value;
	}
	if(midiMessage.control == 5){
		sliders[5] = midiMessage.value;
	}
	if(midiMessage.control == 6){
		sliders[6] = midiMessage.value;
	}
	if(midiMessage.control == 7){
		sliders[7] = midiMessage.value;
	}
    
	////////////////////////////////////
	//		    	KNOBS   		  //
	////////////////////////////////////
	
	if(midiMessage.control == 16){
		knobs[0] = midiMessage.value;
	}
	if(midiMessage.control == 17){
		knobs[1] = midiMessage.value;
	}
	if(midiMessage.control == 18){
		knobs[2] = midiMessage.value;
	}
	if(midiMessage.control == 19){
		knobs[3] = midiMessage.value;
	}
	if(midiMessage.control == 20){
		knobs[4] = midiMessage.value;
	}	
	if(midiMessage.control == 21){
		knobs[5] = midiMessage.value;
	}
	if(midiMessage.control == 22){
		knobs[6] = midiMessage.value;
	}
	if(midiMessage.control == 23){
		knobs[7] = midiMessage.value;
	}
    
    ////////////////////////////////////
	//		    SOLO BUTTONS		  //
	////////////////////////////////////

    if(midiMessage.control == 32 && midiMessage.value == 127){
        buttonsSolo[0] = true;
    } else if(midiMessage.control == 32 && midiMessage.value == 0){
        buttonsSolo[0] = false;
    }
    if(midiMessage.control == 33 && midiMessage.value == 127){
        buttonsSolo[1] = true;
    } else if(midiMessage.control == 33 && midiMessage.value == 0){
        buttonsSolo[1] = false;
    }
    if(midiMessage.control == 34 && midiMessage.value == 127){
        buttonsSolo[2] = true;
    } else if(midiMessage.control == 34 && midiMessage.value == 0){
        buttonsSolo[2] = false;
    }
    if(midiMessage.control == 35 && midiMessage.value == 127){
        buttonsSolo[3] = true;
    } else if(midiMessage.control == 35 && midiMessage.value == 0){
        buttonsSolo[3] = false;
    }
    if(midiMessage.control == 36 && midiMessage.value == 127){
        buttonsSolo[4] = true;
    } else if(midiMessage.control == 36 && midiMessage.value == 0){
        buttonsSolo[4] = false;
    }
    if(midiMessage.control == 37 && midiMessage.value == 127){
        buttonsSolo[5] = true;
    } else if(midiMessage.control == 37 && midiMessage.value == 0){
        buttonsSolo[5] = false;
    }
    if(midiMessage.control == 38 && midiMessage.value == 127){
        buttonsSolo[6] = true;
    } else if(midiMessage.control == 38 && midiMessage.value == 0){
        buttonsSolo[6] = false;
    }
    if(midiMessage.control == 39 && midiMessage.value == 127){
        buttonsSolo[7] = true;
    } else if(midiMessage.control == 39 && midiMessage.value == 0){
        buttonsSolo[7] = false;
    }
    
    ////////////////////////////////////
	//		    MUTE BUTTONS		  //
	////////////////////////////////////
    
    if(midiMessage.control == 48 && midiMessage.value == 127){
        buttonsMute[0] = true;
    } else if(midiMessage.control == 48 && midiMessage.value == 0){
        buttonsMute[0] = false;
    }
    if(midiMessage.control == 49 && midiMessage.value == 127){
        buttonsMute[1] = true;
    } else if(midiMessage.control == 49 && midiMessage.value == 0){
        buttonsMute[1] = false;
    }
    if(midiMessage.control == 50 && midiMessage.value == 127){
        buttonsMute[2] = true;
    } else if(midiMessage.control == 50 && midiMessage.value == 0){
        buttonsMute[2] = false;
    }
    if(midiMessage.control == 51 && midiMessage.value == 127){
        buttonsMute[3] = true;
    } else if(midiMessage.control == 51 && midiMessage.value == 0){
        buttonsMute[3] = false;
    }
    if(midiMessage.control == 52 && midiMessage.value == 127){
        buttonsMute[4] = true;
    } else if(midiMessage.control == 52 && midiMessage.value == 0){
        buttonsMute[4] = false;
    }
    if(midiMessage.control == 53 && midiMessage.value == 127){
        buttonsMute[5] = true;
    } else if(midiMessage.control == 53 && midiMessage.value == 0){
        buttonsMute[5] = false;
    }
    if(midiMessage.control == 54 && midiMessage.value == 127){
        buttonsMute[6] = true;
    } else if(midiMessage.control == 54 && midiMessage.value == 0){
        buttonsMute[6] = false;
    }
    if(midiMessage.control == 55 && midiMessage.value == 127){
        buttonsMute[7] = true;
    } else if(midiMessage.control == 55 && midiMessage.value == 0){
        buttonsMute[7] = false;
    }

    ////////////////////////////////////
	//		    RECORD BUTTONS		  //
	////////////////////////////////////
    
    if(midiMessage.control == 64 && midiMessage.value == 127){
        buttonsRec[0] = true;
    } else if(midiMessage.control == 64 && midiMessage.value == 0){
        buttonsRec[0] = false;
    }
    if(midiMessage.control == 65 && midiMessage.value == 127){
        buttonsRec[1] = true;
    } else if(midiMessage.control == 65 && midiMessage.value == 0){
        buttonsRec[1] = false;
    }
    if(midiMessage.control == 66 && midiMessage.value == 127){
        buttonsRec[2] = true;
    } else if(midiMessage.control == 66 && midiMessage.value == 0){
        buttonsRec[2] = false;
    }
    if(midiMessage.control == 67 && midiMessage.value == 127){
        buttonsRec[3] = true;
    } else if(midiMessage.control == 67 && midiMessage.value == 0){
        buttonsRec[3] = false;
    }
    if(midiMessage.control == 68 && midiMessage.value == 127){
        buttonsRec[4] = true;
    } else if(midiMessage.control == 68 && midiMessage.value == 0){
        buttonsRec[4] = false;
    }
    if(midiMessage.control == 69 && midiMessage.value == 127){
        buttonsRec[5] = true;
    } else if(midiMessage.control == 69 && midiMessage.value == 0){
        buttonsRec[5] = false;
    }
    if(midiMessage.control == 70 && midiMessage.value == 127){
        buttonsRec[6] = true;
    } else if(midiMessage.control == 70 && midiMessage.value == 0){
        buttonsRec[6] = false;
    }
    if(midiMessage.control == 71 && midiMessage.value == 127){
        buttonsRec[7] = true;
    } else if(midiMessage.control == 71 && midiMessage.value == 0){
        buttonsRec[7] = false;
    }
    
    ////////////////////////////////////
	//		    LEFT BUTTONS		  //
	////////////////////////////////////
    if(midiMessage.control == 58 && midiMessage.value == 127){
        buttonTrackLeft = true;
    } else if(midiMessage.control == 58 && midiMessage.value == 0){
        buttonTrackLeft = false;
    }
    if(midiMessage.control == 59 && midiMessage.value == 127){
        buttonTrackRight = true;
    } else if(midiMessage.control == 59 && midiMessage.value == 0){
        buttonTrackRight = false;
    }
    if(midiMessage.control == 46 && midiMessage.value == 127){
        buttonCycle = true;
    } else if(midiMessage.control == 46 && midiMessage.value == 0){
        buttonCycle = false;
    }
    if(midiMessage.control == 60 && midiMessage.value == 127){
        buttonMarkerSet = true;
    } else if(midiMessage.control == 60 && midiMessage.value == 0){
        buttonMarkerSet = false;
    }
    if(midiMessage.control == 61 && midiMessage.value == 127){
        buttonMarkerLeft = true;
    } else if(midiMessage.control == 61 && midiMessage.value == 0){
        buttonMarkerLeft = false;
    }
    if(midiMessage.control == 62 && midiMessage.value == 127){
        buttonMarkerRight = true;
    } else if(midiMessage.control == 62 && midiMessage.value == 0){
        buttonMarkerRight = false;
    }
    if(midiMessage.control == 43 && midiMessage.value == 127){
        buttonRewind = true;
    } else if(midiMessage.control == 43 && midiMessage.value == 0){
        buttonRewind = false;
    }
    if(midiMessage.control == 44 && midiMessage.value == 127){
        buttonFastForward = true;
    } else if(midiMessage.control == 44 && midiMessage.value == 0){
        buttonFastForward = false;
    }
    if(midiMessage.control == 42 && midiMessage.value == 127){
        buttonStop = true;
    } else if(midiMessage.control == 42 && midiMessage.value == 0){
        buttonStop = false;
    }
    if(midiMessage.control == 41 && midiMessage.value == 127){
        buttonPlay = true;
    } else if(midiMessage.control == 41 && midiMessage.value == 0){
        buttonPlay = false;
    }
    if(midiMessage.control == 45 && midiMessage.value == 127){
        buttonRecord = true;
    } else if(midiMessage.control == 45 && midiMessage.value == 0){
        buttonRecord = false;
    }
    
}

//--------------------------------------------------------------
void Korg::draw() {
	
	ofSetColor(155,0,0);

    ofNoFill();
    ofRect(0,30,ofGetWidth(),70);
    ofRect(0,110,ofGetWidth(),ofGetHeight()-120);

    ofSetColor(0);
    ofDrawBitmapString("KORG NANO KONTROL 2 ", 40,20);

    //Track
    ofDrawBitmapString("trackLeft = " + ofToString(buttonTrackLeft), 40,50);
    ofDrawBitmapString("trackRight = " + ofToString(buttonTrackRight), 170,50);
    
    //Maker
    ofDrawBitmapString("cycle = " + ofToString(buttonCycle), 40,70);
    ofDrawBitmapString("markerSet = " + ofToString(buttonMarkerSet), 310,70);
    ofDrawBitmapString("markerLeft = " + ofToString(buttonMarkerLeft), 450,70);
    ofDrawBitmapString("markerRight = " + ofToString(buttonMarkerRight), 590,70);
    
    //Transport
    ofDrawBitmapString("Rewind = " + ofToString(buttonRewind), 40,90);
    ofDrawBitmapString("FastForward = " + ofToString(buttonFastForward), 170,90);
    ofDrawBitmapString("Stop = " + ofToString(buttonStop), 310,90);
    ofDrawBitmapString("Play = " + ofToString(buttonPlay), 450,90);
    ofDrawBitmapString("Record = " + ofToString(buttonRecord), 590,90);


    //Sliders
    ofDrawBitmapString("slider1 = " + ofToString(sliders[0]), 40,130);
    ofDrawBitmapString("slider2 = " + ofToString(sliders[1]), 40,150);
    ofDrawBitmapString("slider3 = " + ofToString(sliders[2]), 40,170);
    ofDrawBitmapString("slider4 = " + ofToString(sliders[3]), 40,190);
    ofDrawBitmapString("slider5 = " + ofToString(sliders[4]), 40,210);
    ofDrawBitmapString("slider6 = " + ofToString(sliders[5]), 40,230);
    ofDrawBitmapString("slider7 = " + ofToString(sliders[6]), 40,250);
    ofDrawBitmapString("slider8 = " + ofToString(sliders[7]), 40,270);
    
    //Knobs
    ofDrawBitmapString("knobs1 = " + ofToString(knobs[0]), 180,130);
    ofDrawBitmapString("knobs2 = " + ofToString(knobs[1]), 180,150);
    ofDrawBitmapString("knobs3 = " + ofToString(knobs[2]), 180,170);
    ofDrawBitmapString("knobs4 = " + ofToString(knobs[3]), 180,190);
    ofDrawBitmapString("knobs5 = " + ofToString(knobs[4]), 180,210);
    ofDrawBitmapString("knobs6 = " + ofToString(knobs[5]), 180,230);
    ofDrawBitmapString("knobs7 = " + ofToString(knobs[6]), 180,250);
    ofDrawBitmapString("knobs8 = " + ofToString(knobs[7]), 180,270);
    
    //Solo Buttons
    ofDrawBitmapString("SoloButton1 = " + ofToString(buttonsSolo[0]), 320,130);
    ofDrawBitmapString("SoloButton2 = " + ofToString(buttonsSolo[1]), 320,150);
    ofDrawBitmapString("SoloButton3 = " + ofToString(buttonsSolo[2]), 320,170);
    ofDrawBitmapString("SoloButton4 = " + ofToString(buttonsSolo[3]), 320,190);
    ofDrawBitmapString("SoloButton5 = " + ofToString(buttonsSolo[4]), 320,210);
    ofDrawBitmapString("SoloButton6 = " + ofToString(buttonsSolo[5]), 320,230);
    ofDrawBitmapString("SoloButton7 = " + ofToString(buttonsSolo[6]), 320,250);
    ofDrawBitmapString("SoloButton8 = " + ofToString(buttonsSolo[7]), 320,270);
    
    //Mute Buttons
    ofDrawBitmapString("MuteButton1 = " + ofToString(buttonsMute[0]), 460,130);
    ofDrawBitmapString("MuteButton2 = " + ofToString(buttonsMute[1]), 460,150);
    ofDrawBitmapString("MuteButton3 = " + ofToString(buttonsMute[2]), 460,170);
    ofDrawBitmapString("MuteButton4 = " + ofToString(buttonsMute[3]), 460,190);
    ofDrawBitmapString("MuteButton5 = " + ofToString(buttonsMute[4]), 460,210);
    ofDrawBitmapString("MuteButton6 = " + ofToString(buttonsMute[5]), 460,230);
    ofDrawBitmapString("MuteButton7 = " + ofToString(buttonsMute[6]), 460,250);
    ofDrawBitmapString("MuteButton8 = " + ofToString(buttonsMute[7]), 460,270);
    
    //Record Buttons
    ofDrawBitmapString("RecButton1 = " + ofToString(buttonsRec[0]), 600,130);
    ofDrawBitmapString("RecButton2 = " + ofToString(buttonsRec[1]), 600,150);
    ofDrawBitmapString("RecButton3 = " + ofToString(buttonsRec[2]), 600,170);
    ofDrawBitmapString("RecButton4 = " + ofToString(buttonsRec[3]), 600,190);
    ofDrawBitmapString("RecButton5 = " + ofToString(buttonsRec[4]), 600,210);
    ofDrawBitmapString("RecButton6 = " + ofToString(buttonsRec[5]), 600,230);
    ofDrawBitmapString("RecButton7 = " + ofToString(buttonsRec[6]), 600,250);
    ofDrawBitmapString("RecButton8 = " + ofToString(buttonsRec[7]), 600,270);
    
	
}

//--------------------------------------------------------------
void Korg::exit() {
	
	// clean up
	midiIn.closePort();
	midiIn.removeListener(this);
}

//--------------------------------------------------------------
void Korg::newMidiMessage(ofxMidiMessage& msg) {
	
	// make a copy of the latest message
	midiMessage = msg;
}

