#include "ParticleSystem.h"

// Come back and clean this.
void ParticleSystem::update(ofPolyline poly) {
  for (int i = 0; i < Max_Particles; i++)
    {
        makeNewParticle(ofRandom(ofGetWidth()), 0);
    }

    ofRectangle screenRect(0, 0, ofGetWidth(), ofGetHeight());

    //glm::vec3 mouse(ofGetMouseX(), ofGetMouseY(), 0);

    // Get an iterator that points to the first element in our vector.
    auto iter = particles.begin();

    // Iterate through all particles.
    while (iter != particles.end())
    {
        // Set our standard acceleration.
        iter->acceleration.x = 0.1;

        //float distance = glm::distance(mouse, iter->position);
      
        glm::vec3 pos(iter->position.x, iter->position.y, iter->position.z);
        glm::vec3 forceDirection;
      
        // Change the force direction based on the bounding box of my position.
        if (poly.inside(pos)) {
          //forceDirection = glm::normalize(pos - poly.getClosestPoint(pos)) * -5;
          iter = particles.erase(iter);
        } else {
          //forceDirection = glm::normalize(mouse - iter->position) * -1;
        }
      
        //float forceStrength = ofMap(distance, 0, 200, 0.1, 0, true);

       // iter->force = forceDirection * forceStrength;
      
        // Updating the particle properties. 
        iter->update();

        // Is the current particle on the screen?
        if (screenRect.inside(iter->position) == false)
        {
            iter = particles.erase(iter);
        }
        else
        {
            iter++;
        }
    }
}

void ParticleSystem::update() {
    for (int i = 0; i < Max_Particles; i++)
    {
        makeNewParticle(ofRandom(ofGetWidth()), 0);
    }

    ofRectangle screenRect(0, 0, ofGetWidth(), ofGetHeight());

    glm::vec3 mouse(ofGetMouseX(), ofGetMouseY(), 0);

    // Get an iterator that points to the first element in our vector.
    auto iter = particles.begin();

    // Iterate through all particles.
    while (iter != particles.end())
    {
        // Set our standard acceleration.
        iter->acceleration.x = 0.1;

        float distance = glm::distance(mouse, iter->position);
      
        // Change the force direction based on the bounding box of my position.
        glm::vec3 forceDirection = glm::normalize(mouse - iter->position) * -1;
        float forceStrength = ofMap(distance, 0, 200, 0.1, 0, true);

        iter->force = forceDirection * forceStrength;
      
        // Updating the particle properties. 
        iter->update();

        // Is the current particle on the screen?
        if (screenRect.inside(iter->position) == false)
        {
            iter = particles.erase(iter);
        }
        else
        {
            iter++;
        }
    }
}

void ParticleSystem::draw() {
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (Particle& p: particles)
    {
        p.draw();
    }

    ofSetColor(255);
    ofDrawBitmapString("Num Particles: " + ofToString(particles.size()), 14, 14);
}

void ParticleSystem::makeNewParticle(float x, float y)
{
    Particle p;
    // Set initial positions.
    p.position.x = x;
    p.position.y = y;
    p.position.z = 0;

    // Set initial velocities.
    p.velocity.x = ofRandom(-2, 2);
    p.velocity.y = ofRandom(-5, 5);
    p.velocity.z = 0;

    // Set inital accelerations.
    p.acceleration.x = 0;
    p.acceleration.y = 0.1;
    p.acceleration.z = 0;

    // Set angular velocity.
    p.angularVelocity.x = 0;
    p.angularVelocity.y = 0;
    p.angularVelocity.z = ofRandom(-2, 2);

    // Set color.
    p.color = ofColor(ofRandom(180, 200), 100);

    // Add a copy to our vector.
    particles.push_back(p);

}
