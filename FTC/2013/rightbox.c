#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  none)
#pragma config(Sensor, S1,     touch,          sensorI2CMuxController)
#pragma config(Sensor, S2,     ir,             sensorNone)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     leftWheel,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     rightWheel,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     flagRaiser,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     pullupRaise,   tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    deployArm,            tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C2_2,    dropBlockArm,         tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "move_turns_vars.h"
#include "movement.h"
#include "surfaces.h"

/*
Robot is moving backward the entire time.
Set it up so the front faces the wall.
*/
/*
task main()
{
	waitForStart();
	init();

	wait1Msec(2000);

	servo[dropBlockArm] = BLOCK_ARM_FULL;

	wait1Msec(3000);
	servo[dropBlockArm] = BLOCK_ARM_DOWN;


	wait1Msec(10000);
}
*/
task main()
{
	waitforStart();
	init();

	move(-20); //negative distance, position for the turn
	turnReverse(45);

	dropBlock();
	wait1Msec(50);

	servo[deployArm] = 0;
	wait1Msec(3000);
	servo[deployArm] = 128;

	move(-35); //to ramp
	turnReverse(-95);
	move(-75); //onto ramp
	//stop();

}
