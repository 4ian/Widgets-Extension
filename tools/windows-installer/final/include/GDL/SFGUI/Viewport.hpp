#pragma once
#include <SFGUI/Config.hpp>
#include <SFGUI/Bin.hpp>
#include <SFGUI/Adjustment.hpp>
#include <SFGUI/SharedPtr.hpp>

namespace sfg {

/** Viewport.
 */
class SFGUI_API Viewport : public Bin {
	public:
		typedef SharedPtr<Viewport> Ptr; //!< Shared pointer.
		typedef SharedPtr<const Viewport> PtrConst; //!< Shared pointer.

		/** Create viewport.
		 * @return Viewport.
		 */
		static Ptr Create();

		/** Create viewport with the provided adjustments.
		 * @param horizontal_adjustment Horizontal adjustment.
		 * @param vertical_adjustment Vertical adjustment.
		 * @return Viewport.
		 */
		static Ptr Create( const Adjustment::Ptr& horizontal_adjustment, const Adjustment::Ptr& vertical_adjustment );

		/** Expose.
		 * Render widget to given target.
		 * @param target SFML render target.
		 */
		virtual void Expose( CullingTarget& target, const struct NoFlushTag& ) const;

		/** Get absolute position on virtual screen: always (0,0)
		 * @return Absolute position on virtual screen: always (0,0).
		 */
		virtual sf::Vector2f GetAbsolutePosition() const;

		/** Get the horizontal Adjustment for this Viewport.
		 * @return Horizontal Adjustment for this Viewport.
		 */
		const Adjustment::Ptr& GetHorizontalAdjustment() const;

		/** Set the horizontal adjustment of this Viewport
		 * @param horizontal_adjustment Horizontal Adjustment
		 */
		void SetHorizontalAdjustment( const Adjustment::Ptr& horizontal_adjustment );

		/** Get the vertical Adjustment for this Viewport.
		 * @return Vertical Adjustment for this Viewport.
		 */
		const Adjustment::Ptr& GetVerticalAdjustment() const;

		/** Set the vertical adjustment of this Viewport
		 * @param vertical_adjustment Vertical Adjustment
		 */
		void SetVerticalAdjustment( const Adjustment::Ptr& vertical_adjustment );

		/** Handle SFML event.
		 * Handle an SFML event and fire proper signals.
		 * @return true when event has been processed (eaten).
		 */
		virtual void HandleEvent( const sf::Event& event );

		virtual const std::string& GetName() const;

	protected:
		sf::Vector2f CalculateRequisition();

		virtual void HandleAllocationChange( const sf::FloatRect& old_allocation );

	private:
		Viewport( const Adjustment::Ptr& horizontal_adjustment, const Adjustment::Ptr& vertical_adjustment );

		void HandleRequisitionChange();

		Adjustment::Ptr m_horizontal_adjustment;
		Adjustment::Ptr m_vertical_adjustment;
};

}
