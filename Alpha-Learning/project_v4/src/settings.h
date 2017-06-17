#ifndef SETTINGS
#define SETTINGS

#include "ofMain.h"

// Global

#define SCALE 1

#define MAC_SPACE_A 324
#define MAC_SPACE_B 234
#define WINDOWS_SPACE 123

#define MAC_SHIFT_A 345
#define MAC_SHIFT_B 466
#define WINDOWS_SHIFT 577

#define STARTLANDING 4.5*60 // Seconds
#define DEADLINE 5*60 // Seconds

// --- Drone ---

// Drone - View

#define DRONE_VIEW_ANGLE 73

#define DRONE_VIEW_PIXELCM 5
#define DRONE_VIEW_H 720
#define DRONE_VIEW_W 1280

#define DRONE_VIEW_COUNT 4

// Drone - Safety Distance

#define DRONE_SAFETYDISTANCE 50 // "Radius"
#define DRONE_ANGLE_OFFSET 2

// Drone - Landing Platform

#define DRONE_START_X 300
#define DRONE_START_Y 20
#define DRONE_START_Z 300

// Drone - Speeds

#define DRONE_STEADY_SPEED 0.833
#define DRONE_NORMAL_SPEED 1.667 // m/s
#define DRONE_FAST_SPEED 2
#define DRONE_INSANE_SPEED 5
#define DRONE_LUDICROUS_SPEED 10

#define DRONE_ROTATION_SPEED 5

#define DRONE_ORIENTATION_VECTOR 100

// Drone - Appearance

#define DRONE_BOX_X 44
#define DRONE_BOX_Y 12
#define DRONE_BOX_Z 44

// Room

#define ROOM_SIZE_X 1200
#define ROOM_SIZE_Y 400
#define ROOM_SIZE_Z 1200

// Hoop

#define HOOP_COUNT 6

#define HOOP_RADIUS_A 40
#define HOOP_RADIUS_B 45
#define HOOP_RADIUS_C 50
#define HOOP_THICKNESS 2

#define HOOP_PASSAGE_X 140
#define HOOP_PASSAGE_Y 20
#define HOOP_PASSAGE_Z 20

#define HOOP_WAYPOINT_OFFSET 111

#define HOOP_SAFETYDISTANCE 101

// Hoop Random

#define HOOP_RANDOM true

// Hoop A

#define HOOP_A_X 100
#define HOOP_A_Y 200
#define HOOP_A_Z 100

// Hoop B

#define HOOP_B_X -200
#define HOOP_B_Y 200
#define HOOP_B_Z 200

// Hoop C

#define HOOP_C_X -300
#define HOOP_C_Y 200
#define HOOP_C_Z -200

// Hoop D

#define HOOP_D_X 400
#define HOOP_D_Y 200
#define HOOP_D_Z -400

// Hoop E

#define HOOP_E_X 400
#define HOOP_E_Y 200
#define HOOP_E_Z -400

// Hoop F

#define HOOP_F_X 400
#define HOOP_F_Y 200
#define HOOP_F_Z -400

// QR

#define QR_REAL_COUNT 20

// Wall 1

#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"

// Wall 2

#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"

// Wall 3

#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"

// Wall 4

#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"
#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"

// Original Test QR

#define QR_COUNT 4

#define QR_SIZE_Y 22
#define QR_SIZE_X 22

#define QR_A_X 600
#define QR_A_Y 180
#define QR_A_Z 200
#define QR_A_TEXT "A"

#define QR_B_X 600
#define QR_B_Y 180
#define QR_B_Z -200
#define QR_A_TEXT "B"

#define QR_C_X -600
#define QR_C_Y 180
#define QR_C_Z -200
#define QR_A_TEXT "C"

#define QR_D_X -600
#define QR_D_Y 180
#define QR_D_Z 200
#define QR_A_TEXT "D"

// Landing Platform

#define LANDINGPLATFORM_X 100
#define LANDINGPLATFORM_Z 100

#define LANDINGPLATFORM_POS_X 300
#define LANDINGPLATFORM_POS_Z 300

#define LANDINGPLATFORM_POS_Y 100 // Landing CheckPoint offset

// Waypoint

#define WAYPOINT_X 20
#define WAYPOINT_Y 20
#define WAYPOINT_Z 20

#define WAYPOINT_DISTANCE 7

// DRONE AI

#define LOOP_TRAJECTORY_MAX 256
#define TAKEOFF_TRAJECTORY_MAX 8
#define LANDING_TRAJECTORY_MAX 8

#endif /* end of include guard: SETTINGS */
