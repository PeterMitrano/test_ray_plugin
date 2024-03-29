#include "test_ray_plugin.h"

using namespace gazebo;

void TestRayPlugin::Load(physics::WorldPtr world, sdf::ElementPtr _sdf)
{
  world_ = world;
  auto engine = world->Physics();
  engine->InitForThread();
  auto ray_shape = engine->CreateShape("ray", gazebo::physics::CollisionPtr());
  ray = boost::dynamic_pointer_cast<gazebo::physics::RayShape>(ray_shape);
  ignition::math::Vector3d start, end;
  start.Z(5);
  end.Z(0.01);
  start.X(0);
  start.Y(0);
  end.X(0);
  end.Y(0);

  ray->SetPoints(start, end);

  this->update_connection_ = event::Events::ConnectWorldUpdateBegin(boost::bind(&TestRayPlugin::OnUpdate, this));
}

void TestRayPlugin::OnUpdate()
{
  std::string entityName;
  double dist{0};
  ray->GetIntersection(dist, entityName);
  std::cout << entityName << "  " << dist << '\n';
}

// Register this plugin with the simulator
GZ_REGISTER_WORLD_PLUGIN(TestRayPlugin)
