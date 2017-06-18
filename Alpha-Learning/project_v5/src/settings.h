#ifndef SETTINGS
#define SETTINGS

#include "ofMain.h"

// Global

#define SCALE 1

#define MAC_SPACE 32
#define WINDOWS_SPACE 123

#define MAC_SHIFT_A 2304
#define MAC_SHIFT_B 2305
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

#define X1 0.0003
#define PXCM 1188.769441 // At 100 cms

// Drone - Safety Distance

#define DRONE_SAFETYDISTANCE 50 // "Radius"
#define DRONE_ANGLE_OFFSET 2

// Drone - Landing Platform

#define DRONE_START_X 300
#define DRONE_START_Y 20
#define DRONE_START_Z 300

// Drone - Speeds

#define DRONE_STEADY_SPEED 0.5
#define DRONE_NORMAL_SPEED 1 // m/s
#define DRONE_FAST_SPEED 2
#define DRONE_INSANE_SPEED 10
#define DRONE_LUDICROUS_SPEED 1000

#define DRONE_MS_TO_FPS 1.6667

#define DRONE_ROTATION_SPEED 1
#define DRONE_ANGLE_FPS 60

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

#define HOOP_COUNT 2

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

// QRs

#define P00 1
#define P01 2
#define P02 4
#define P03 8
#define P04 16
#define P05 32

#define W0000 64
#define W0001 128
#define W0002 256
#define W0003 512
#define W0004 1024
#define W0100 2048
#define W0101 4096
#define W0102 8192
#define W0103 16384
#define W0104 32798

#define W0200 65536
#define W0201 131072
#define W0202 262144
#define W0203 524288
#define W0204 1048576

#define W0300 2097152
#define W0301 4194304
#define W0302 8388608
#define W0303 16777216
#define W0304 33554432

#endif /* end of include guard: SETTINGS */
