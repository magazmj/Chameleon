//  Created by Sean Heber on 5/27/10.
#import "UIEvent.h"

@interface UIResponder : NSObject

- (UIResponder *)nextResponder;
- (BOOL)isFirstResponder;
- (BOOL)canBecomeFirstResponder;
- (BOOL)becomeFirstResponder;
- (BOOL)canResignFirstResponder;
- (BOOL)resignFirstResponder;

- (BOOL)canPerformAction:(SEL)action withSender:(id)sender;

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event;

- (void)motionBegan:(UIEventSubtype)motion withEvent:(UIEvent *)event;
- (void)motionEnded:(UIEventSubtype)motion withEvent:(UIEvent *)event;
- (void)motionCancelled:(UIEventSubtype)motion withEvent:(UIEvent *)event;

@property (readonly) NSUndoManager *undoManager;

@end

@interface UIResponder (OSXExtensions)
// This message is sent up the responder chain so that views behind other views can make use of the scroll wheel (such as UIScrollView).
- (void)scrollWheelMoved:(CGPoint)delta withEvent:(UIEvent *)event;

// This is sent up the responder chain when the app gets a rightMouseDown-like event from OSX. There is no rightMouseDragged or rightMouseUp.
- (void)rightClick:(UITouch *)touch withEvent:(UIEvent *)event;

// These messages are sent up (down?) the responder chain. You may get these often - especially when the mouse moves over a view that has a lot
// of smaller subviews in it as the messages will be sent each time the view under the cursor changes. These only happen during normal mouse
// movement - not when clicking, click-dragging, etc so it won't happen in all possible cases that might maybe make sense. Also, due to the
// bolted-on nature of this, I'm not entirely convinced it is delivered from the best spot - but in practice, it'll probably be okay.
- (void)mouseEntered:(UIView *)view withEvent:(UIEvent *)event;
- (void)mouseExited:(UIView *)view withEvent:(UIEvent *)event;

// This passed along the responder chain like everything else.
- (void)mouseMoved:(CGPoint)delta withEvent:(UIEvent *)event;

// Return an NSCursor if you want to modify it or nil to use the default arrow. Follows responder chain.
- (id)mouseCursorForEvent:(UIEvent *)event;	// return an NSCursor if you want to modify it, return nil to use default
@end
