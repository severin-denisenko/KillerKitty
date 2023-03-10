//
// Created by Severin on 08.03.2023.
//

#ifndef KILLERKITTY_PHYSICSENGINE_H
#define KILLERKITTY_PHYSICSENGINE_H

#include "box2d/b2_world.h"
#include "SFML/System.hpp"

#include "engine/Entities/RigidBody.h"

namespace kke {

    class RigidBody;

    class PhysicsEngine {
    public:
        PhysicsEngine();

        void Update(sf::Time deltaTime);

        int velocityIterations = 6;
        int positionIterations = 2;
        float timeMultiplier = 1.f;

        void RegisterBody(RigidBody& rigidBody);

    private:
        b2World world;
        std::vector<RigidBody*> bodies;
    };

} // kke

#endif //KILLERKITTY_PHYSICSENGINE_H
