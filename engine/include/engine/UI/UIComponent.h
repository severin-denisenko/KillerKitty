//
// Created by Severin on 12.03.2023.
//

#ifndef KILLERKITTY_UICOMPONENT_H
#define KILLERKITTY_UICOMPONENT_H

#include <SFML/Graphics.hpp>

namespace kke {

    class UIComponent  : public sf::Drawable, public sf::Transformable, private sf::NonCopyable {
    public:
        UIComponent();
        virtual ~UIComponent();

        virtual bool isSelectable() const = 0;

        bool isSelected() const;
        virtual void select();
        virtual void deselect();

        virtual bool isActive() const;
        virtual void activate();
        virtual void deactivate();

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        virtual void handleEvent(const sf::Event& event) = 0;

    private:
        bool selected = false;
        bool active = false;
    };

} // kke

#endif //KILLERKITTY_UICOMPONENT_H
