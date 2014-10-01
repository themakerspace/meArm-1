// Control meArm servos from POST requests
Servo yServo;  // create servo object to control a servo a maximum of eight servo objects can be created
Servo clawServo;
Servo xServo;
Servo baseServo;

char lastCommand[64] = "NONE";

int ypos = 90;    // variables to store the servo "default" positions
int basepos = 0;
int clawpos = 30;
int xpos = 90;

void setup()
{
  yServo.attach(A0);      // up and down
  clawServo.attach(A1);   // claw
  xServo.attach(A4);      // fwd and bk
  baseServo.attach(A5);   // base
  
  Spark.function("move",move);
  Spark.variable("lastCommand", &lastCommand, STRING);
  
  // Defaults
  yServo.write(ypos);
  clawServo.write(clawpos);
  xServo.write(xpos);
  baseServo.write(basepos);
}


void loop()
{
    // nothing to do here, we don't want anything looping right now. 
    // I guess if this was an automated arm that did a specific task, we could demo that here
  
}

int move(String command) {
    command.trim();
    
    int    ledPin = -1;
    char * params = new char[command.length() + 1];

    strcpy(params, command.c_str());
    char * param1 = strtok(params, ",");
    char * param2 = strtok(NULL, ",");

    int cmd = 0;
    if(param1 != NULL && param2 != NULL ) {
        String cmd = param1;
        cmd.toCharArray(lastCommand, 64);
        int pos = atoi(param2);
        if(cmd.equals("claw")) {
            clawpos = pos;
            clawServo.write(clawpos);
            delay(150);
            return clawpos;
        }
        else if(cmd.equals("moveup")) {
            ypos = pos;
            yServo.write(ypos);
            delay(150);
            return ypos;
        }
        else if(cmd.equals("movefwd")) {
            xpos = pos;
            xServo.write(xpos);
            delay(150);
            return xpos;
        }
        else if(cmd.equals("rotate")) {
            basepos = pos;
            baseServo.write(basepos);
            delay(150);
            return basepos;
        }
      
    }
    return -1;
}
