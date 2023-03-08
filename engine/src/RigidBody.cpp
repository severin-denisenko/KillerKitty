//
// Created by Severin on 08.03.2023.
//

#include "RigidBody.h"

namespace kke {
    RigidBody::RigidBody(PhysicsEngine& physicsEngine, bool dynamic) : physicsEngine(physicsEngine) {
        dynamicBox.SetAsBox(1.0f, 1.0f);
        if (dynamic)
            bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(0.0f, 4.0f);
        body = physicsEngine.world.CreateBody(&bodyDef);

        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        fixture = body->CreateFixture(&fixtureDef);
    }

    void RigidBody::updateCurrent(sf::Time dt) {
        b2Vec2 position = body->GetPosition();
        setPosition(position.x, position.y);
    }

    void RigidBody::setPosition(float x, float y) {
        Transformable::setPosition(x, y);

        auto p = body->GetPosition();
        auto a = body->GetAngle();

        body->SetTransform(b2Vec2(x, y), a);
    }

    void RigidBody::setSize(float x, float y) {
        body->DestroyFixture(fixture);
        dynamicBox.SetAsBox(x, y);
        fixtureDef.shape = &dynamicBox;
        fixture = body->CreateFixture(&fixtureDef);
    }
} // kke