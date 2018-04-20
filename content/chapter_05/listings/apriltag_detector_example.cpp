// Addtional code goes before

// The variable "I" contains the camera image

// Create detector for the 36h11 AprilTag family
vpDetectorAprilTag detector(vpDetectorAprilTag::TAG_36h11);

// Detect markers in image
detector.detect(I);

// Get the corners of the first marker in the list
// (counter-clockwise order)
std::vector<vpImagePoint> p = detector.getPolygon(0);
