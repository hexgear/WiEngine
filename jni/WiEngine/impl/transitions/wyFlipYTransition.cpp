/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "wyFlipYTransition.h"
#include <stdlib.h>
#include "wySequence.h"
#include "wyCallFunc.h"
#include "wyDelayTime.h"
#include "wyShow.h"
#include "wyHide.h"
#include "wyOrbitCamera.h"

wyFlipYTransition* wyFlipYTransition::make(float duration, wyScene* inScene, bool toTop) {
	wyFlipYTransition* t = WYNEW wyFlipYTransition(duration, inScene, toTop);
	return (wyFlipYTransition*)t->autoRelease();
}

void wyFlipYTransition::initScenes() {
	m_inScene->setVisible(false);
}

wyIntervalAction* wyFlipYTransition::getInAction() {
    float inDeltaZ, inAngleZ;

    if (m_toTop) {
    	inAngleZ = 90;
        inDeltaZ = -90;
    } else {
    	inAngleZ = 270;
        inDeltaZ = 90;
    }

	// create call func
    wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyTransitionScene::finish));
    wyFiniteTimeAction* call = wyCallFunc::make(ts);

    // create orbit action
    wyIntervalAction* orbit = wyOrbitCamera::make(m_duration / 2, 1, 0, inAngleZ, inDeltaZ, 90, 0);

    // use ease if set
    if(m_inEase) {
    	m_inEase->setWrappedAction(orbit);
    	orbit = m_inEase;
    }

    // create sequence
    wySequence* seq = wySequence::make(wyDelayTime::make(m_duration / 2), wyShow::make(), orbit, call, NULL);

    // return
    return seq;
}

wyIntervalAction* wyFlipYTransition::getOutAction() {
    float outDeltaZ, outAngleZ;

    if (m_toTop) {
    	outAngleZ = 0;
        outDeltaZ = -90;
    } else {
    	outAngleZ = 0;
        outDeltaZ = 90;
    }

    // create orbit action
    wyIntervalAction* orbit = wyOrbitCamera::make(m_duration / 2, 1, 0, outAngleZ, outDeltaZ, 90, 0);

    // use ease if set
    if(m_outEase) {
    	m_outEase->setWrappedAction(orbit);
    	orbit = m_outEase;
    }

    // create sequence
    wySequence* seq = wySequence::make(orbit, wyHide::make(), wyDelayTime::make(m_duration / 2), NULL);

    // return
    return seq;
}

wyFlipYTransition::~wyFlipYTransition() {
}

wyFlipYTransition::wyFlipYTransition(float duration, wyScene* inScene, bool toTop) :
		wyTransitionScene(duration, inScene),
		m_toTop(toTop) {
}
