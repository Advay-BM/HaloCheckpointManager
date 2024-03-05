#include "pch.h"
#include "WaypointList.h"



void Waypoint::serialise(pugi::xml_node wpnode) const
{

	auto posNode = wpnode.append_child("position");
	posNode.append_child("x").text().set(position.x);
	posNode.append_child("y").text().set(position.y);
	posNode.append_child("z").text().set(position.z);

	wpnode.append_child("showDistance").text().set(showDistance);

	wpnode.append_child("enabled").text().set(enabled);

	wpnode.append_child("label").text().set(label.c_str());



}

// deserialisation constructor
Waypoint::Waypoint(pugi::xml_node input)
{
#ifdef HCM_DEBUG
	throw E_NOTIMPL;
#else
	static_assert(false, "IMPLEMENT WAYPOINT (DE)SERIALISATION");
#endif
}


// serialise (output xml to stringstream)
std::ostream& operator<<(std::ostream& os, const WaypointList& dt)
{
	pugi::xml_document doc;

	for (auto& wp : dt.list)
	{
		auto node = doc.append_child("waypoint");
		wp.serialise(node);
	}

	doc.print(os);
	return os;
}




	// deserialisation constructor
WaypointList::WaypointList(pugi::xml_node input)
{
#ifdef HCM_DEBUG
	throw E_NOTIMPL;
#else
	static_assert(false, "IMPLEMENT WAYPOINT (DE)SERIALISATION");
#endif
}