#pragma once

#include <sstream>

#include "../engine/ecs/registry.h"
#include "components.h"

namespace P3D::Application {

class EntityBuilder {
private:
	Engine::Registry64& registry;
	Engine::Registry64::entity_type entity;
	
public:
	explicit EntityBuilder(Engine::Registry64& registry) : registry(registry), entity(registry.create()) {}
	EntityBuilder(Engine::Registry64& registry, const Engine::Registry64::entity_type& entity) : registry(registry), entity(entity) {}

	[[nodiscard]] Engine::Registry64::entity_type get() const {
		return entity;
	}
	
	EntityBuilder& parent(const Engine::Registry64::entity_type& entity) {
		this->registry.setParent(this->entity, entity);

		return *this;
	}

	template<typename... Args>
	EntityBuilder& transform(Args&&... args) {
		this->registry.add<Comp::Transform>(this->entity, std::forward<Args>(args)...);
		
		return *this;
	}

	template<typename... Args>
	EntityBuilder& name(Args&&... args) {
		this->registry.add<Comp::Name>(this->entity, std::forward<Args>(args)...);

		return *this;
	}

	template<typename... Args>
	EntityBuilder& light(Args&&... args) {
		this->registry.add<Comp::Light>(this->entity, std::forward<Args>(args)...);

		return *this;
	}

	template<typename... Args>
	EntityBuilder& collider(Args&&... args) {
		this->registry.add<Comp::Collider>(this->entity, std::forward<Args>(args)...);

		return *this;
	}

	template<typename... Args>
	EntityBuilder& mesh(Args&&... args) {
		this->registry.add<Graphics::Comp::Mesh>(this->entity, std::forward<Args>(args)...);

		return *this;
	}

	template<typename... Args>
	EntityBuilder& material(Args&&... args) {
		this->registry.add<Graphics::Comp::Material>(this->entity, std::forward<Args>(args)...);

		return *this;
	}

	template<typename... Args>
	EntityBuilder& hitbox(Args&&... args) {
		this->registry.add<Comp::Hitbox>(this->entity, std::forward<Args>(args)...);

		return *this;
	}
		
	template<typename... Args>
	EntityBuilder& attachment(Args&&... args) {
		this->registry.add<Comp::Attachment>(this->entity, std::forward<Args>(args)...);

		return *this;
	}

	template<typename... Args>
	EntityBuilder& magneticLink(Args&&... args) {
		this->registry.add<Comp::MagneticLink>(this->entity, std::forward<Args>(args)...);

		return *this;
	}

	template<typename... Args>
	EntityBuilder& elasticLink(Args&&... args) {
		this->registry.add<Comp::ElasticLink>(this->entity, std::forward<Args>(args)...);

		return *this;
	}

	template<typename... Args>
	EntityBuilder& springLink(Args&&... args) {
		this->registry.add<Comp::SpringLink>(this->entity, std::forward<Args>(args)...);

		return *this;
	}

	template<typename... Args>
	EntityBuilder& alignmentLink(Args&&... args) {
		this->registry.add<Comp::AlignmentLink>(this->entity, std::forward<Args>(args)...);

		return *this;
	}

	template<typename... Args>
	EntityBuilder& fixedConstraint(Args&&... args) {
		this->registry.add<Comp::FixedConstraint>(this->entity, std::forward<Args>(args)...);

		return *this;
	}
};

}