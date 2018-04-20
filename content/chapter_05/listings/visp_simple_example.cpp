// Addtional code goes before

// Start a ViSP visual servoing task
vpServo task;

// Configure the visual servoing task where joint velocities are computed
task.setServo(vpServo::EYEINHAND_L_cVe_eJe);

// Interaction matrix is computed with the current visual features s
task.setInteractionMatrixType(vpServo::CURRENT);

// Set control gain
task.setLambda(1.0);
 
// Add feature
task.addFeature(s, s_star);
 
do
{
  // Compute the camera velocities
  v = task.computeControlLaw();
  
  // Update features
  s.buildFrom(cdMc);
 	
  // Get the feature vector difference (error = s^2 - s_star^2)
  error =  ( task.getError() ).sumSquare();
} while (error > 0.0001); 
 
// End visual servoing task
task.kill();
