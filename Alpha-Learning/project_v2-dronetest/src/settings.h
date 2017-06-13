#ifndef SETTINGS
#define SETTINGS

// Global
#define SCALE 1

// Drone
#define DRONE_SAFETYDISTANCE 50 // "Radius"

// Room
#define ROOM_SIZE_X 1200
#define ROOM_SIZE_Y 400
#define ROOM_SIZE_Z 1200

// Hoop
#define HOOP_RADIUS 35
#define HOOP_THICKNESS 2

#define HOOP_HITBOX_X DRONE_SAFETYDISTANCE*2
#define HOOP_HITBOX_Y (DRONE_SAFETYDISTANCE+HOOP_RADIUS)*2
#define HOOP_HITBOX_Z HOOP_HITBOX_Y

#define HOOP_PASSAGE_X 140
#define HOOP_PASSAGE_Y 20
#define HOOP_PASSAGE_Z 20

#define HOOP_WAYPOINT_OFFSET 70

// QR
#define QR_SIZE_Y 29
#define QR_SIZE_X 31

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

#endif /* end of include guard: SETTINGS */
