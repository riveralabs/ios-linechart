//
//  LCDrawingHelper.h
//  ios-linechart
//
//  Created by Axel Rivera on 3/7/14.
//  Copyright (c) 2014 Marcel Ruegenberg. All rights reserved.
//

static void CGContextAddRoundedRect(CGContextRef c, CGRect rect, CGFloat radius) {
	if(2 * radius > rect.size.height) radius = rect.size.height / 2.0;
	if(2 * radius > rect.size.width) radius = rect.size.width / 2.0;
	CGContextAddArc(c, rect.origin.x + radius, rect.origin.y + radius, radius, M_PI, M_PI * 1.5, 0);
	CGContextAddArc(c, rect.origin.x + rect.size.width - radius, rect.origin.y + radius, radius, M_PI * 1.5, M_PI * 2, 0);
	CGContextAddArc(c, rect.origin.x + rect.size.width - radius, rect.origin.y + rect.size.height - radius, radius, M_PI * 2, M_PI * 0.5, 0);
	CGContextAddArc(c, rect.origin.x + radius, rect.origin.y + rect.size.height - radius, radius, M_PI * 0.5, M_PI, 0);
	CGContextAddLineToPoint(c, rect.origin.x, rect.origin.y + radius);
}

static void CGContextFillRoundedRect(CGContextRef c, CGRect rect, CGFloat radius) {
	CGContextBeginPath(c);
	CGContextAddRoundedRect(c, rect, radius);
	CGContextFillPath(c);
}
