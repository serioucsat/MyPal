/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "vm/TaggedProto.h"

#include "jsfun.h"
#include "jsobj.h"

#include "gc/Barrier.h"
#include "gc/Zone.h"

#include "vm/Caches-inl.h"

namespace js {

/* static */ void
InternalBarrierMethods<TaggedProto>::preBarrier(TaggedProto& proto)
{
    InternalBarrierMethods<JSObject*>::preBarrier(proto.toObjectOrNull());
}

/* static */ void
InternalBarrierMethods<TaggedProto>::postBarrier(TaggedProto* vp, TaggedProto prev,
                                                 TaggedProto next)
{
    JSObject* prevObj = prev.isObject() ? prev.toObject() : nullptr;
    JSObject* nextObj = next.isObject() ? next.toObject() : nullptr;
    InternalBarrierMethods<JSObject*>::postBarrier(reinterpret_cast<JSObject**>(vp), prevObj,
                                                   nextObj);
}

/* static */ void
InternalBarrierMethods<TaggedProto>::readBarrier(const TaggedProto& proto)
{
    InternalBarrierMethods<JSObject*>::readBarrier(proto.toObjectOrNull());
}

} // namespace js

js::HashNumber
js::TaggedProto::hashCode() const
{
    return Zone::UniqueIdToHash(uniqueId());
}

bool
js::TaggedProto::hasUniqueId() const
{
    if (!isObject())
        return true;
    JSObject* obj = toObject();
    return obj->zone()->hasUniqueId(obj);
}

bool
js::TaggedProto::ensureUniqueId() const
{
    if (!isObject())
        return true;
    uint64_t unusedId;
    JSObject* obj = toObject();
    return obj->zone()->getUniqueId(obj, &unusedId);
}

uint64_t
js::TaggedProto::uniqueId() const
{
    if (isDynamic())
        return uint64_t(1);
    JSObject* obj = toObjectOrNull();
    if (!obj)
        return uint64_t(0);
    return obj->zone()->getUniqueIdInfallible(obj);
}
