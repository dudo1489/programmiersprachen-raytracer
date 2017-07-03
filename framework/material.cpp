#include "material.hpp"

Material::Material():
	name_{"new_Material"},
	ka_{Color{0.0f,0.1f,0.2f}},
	kd_{Color{0.6f,0.7f,0.8f}},
	ks_{Color{0.3f,0.4f,0.5f}},
	m_{0.9f}{}

Material::Material(string const& name, Color const& ka, Color const& kd, Color const& ks, float m):
	name_{name},
	ka_{ka},
	kd_{kd},
	ks_{ks},
	m_{m}{}