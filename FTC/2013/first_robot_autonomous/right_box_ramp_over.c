#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     touch,          sensorI2CMuxController)
#pragma config(Sensor, S2,     ir,             sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,          flagRaiser,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     rightWheel,    tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftWheel,     tmotorTetrix, PIDControl, encoder)
#pragma config(Servo,  srvo_S1_C2_1,    elevator,             tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C2_2,    elevator2,            tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C2_3,    kicker,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_4,    swiffer,              tServoStandard)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "boilerplate.h"
#include "move_turns_vars.h"
#include "JoystickDriver.c"

task main()
{
	waitForStart();
	init();


	StartTask(moveElevatorUpFull);
	wait1Msec(time_elevator1_up);
	turn(TURN_1);
	move(MOVE_1);
	turn(TURN_2);

	move(MOVE_2);
	gotoBox();

	//start going to the ramp
	turn(TURN_3);

	int startTime = nPgmTime;
	StartTask(moveElevatorDownFull);

	move(MOVE_3);
	turn(TURN_4);
	move(MOVE_4 + MOVE_OVER_5);
	wait1Msec(time_elevator1_down - (nPgmTime - startTime));

	StopTask(moveElevatorDownFull);
	StopTask(moveElevatorUpFull);
}
