#pragma once

#include <SFGUI/Config.hpp>
#include <SFGUI/Bin.hpp>
#include <SFGUI/SharedPtr.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/String.hpp>

namespace sfg {

/** Window.
 */
class SFGUI_API Window : public Bin {
	public:
		typedef SharedPtr<Window> Ptr; //!< Shared pointer.
		typedef SharedPtr<const Window> PtrConst; //!< Shared pointer.

		enum Style {
			NoStyle = 0, //!< Transparent window.
			Titlebar = 1 << 0, //!< Titlebar.
			Background = 1 << 1, //!< Background.
			Resize = 1 << 2, //!< Resizable.
			Toplevel = Titlebar | Background | Resize //!< Toplevel window.
		};

		/** Dtor.
		 */
		virtual ~Window();

		/** Create widget.
		 */
		static Ptr Create();

		virtual const std::string& GetName() const;

		/** Set window title.
		 * @param title Title.
		 */
		void SetTitle( const sf::String& title );

		/** Get window title.
		 * @return Title.
		 */
		const sf::String& GetTitle() const;

		/** Get client area.
		 * @return Rect.
		 */
		sf::FloatRect GetClientRect() const;

		/** Set window style.
		 * Can be a combination of Window::Style values.
		 * @param style New style.
		 */
		void SetStyle( int style );

		/** Get window style.
		 * @return Window style.
		 */
		int GetStyle() const;

		/** Check if the window has a specific style.
		 * @param style Style to check.
		 * @return true when window has desired style.
		 */
		bool HasStyle( Style style ) const;

	protected:
		/** Constructor.
		 */
		Window();

		virtual RenderQueue* InvalidateImpl() const;

		sf::Vector2f CalculateRequisition();

	private:
		void HandleAllocationChange( const sf::FloatRect& old_allocation );
		void HandleMouseButtonEvent( sf::Mouse::Button button, bool press, int x, int y );
		void HandleMouseMoveEvent( int x, int y );
		void HandleAdd( const Widget::Ptr& child );

		sf::Vector2f m_drag_offset;

		sf::String m_title;
		int m_style;

		bool m_dragging;
		bool m_resizing;
};

}
