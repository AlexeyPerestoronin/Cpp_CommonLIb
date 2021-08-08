#pragma once

#include "stdafx.h"

namespace parallelization {
	/// brief: std::mutex based access controller to an object
	/// note1: this class do block the controlled object each time when the take-function invoke and unblock its after release-function invoke
	/// t-param: ObjectType - type of object witch must be under controlling
    template<class ObjectType>
    class access_controller {
        mutable std::mutex d_access{};
        ObjectType d_object;

        public:
        using object_type = ObjectType;

        template<class... ArgsTypes>
        access_controller(ArgsTypes&&... i_args) noexcept
            : d_object{ std::forward<ArgsTypes>(i_args)... } {}

    	/// brief: blocks controlled object
        void take() {
            d_access.lock();
        }

    	/// brief: unblock controlled object
        void release() {
            d_access.unlock();
        }

    	/// brief: gets the pointer to controlled object
        [[nodiscard]] object_type* get_object() {
            return &d_object;
        }

    	/// brief: gets the const pointer to controlled object
        [[nodiscard]] const object_type* get_object() const {
            return &d_object;
        }
    };

	/// brief: the class implements RAII-idiom to getting control the object by means of the controller
	/// note1:
	/// This class not more then wrapper above the controller to using its functionality.
	/// All the controller class types must provide three methods: take, release and get_objects.
	/// t-param: ControlledType - type of the controller object witch provides API to control the object
    template<class ControlledType>
    class synchronizer {
        ControlledType& d_controller;

        public:
        synchronizer(ControlledType& i_accesser) noexcept
            : d_controller{ i_accesser } {
            d_controller.take();
        }

        ~synchronizer() noexcept {
            d_controller.release();
        }

        [[nodiscard]] constexpr typename ControlledType::object_type* operator->() noexcept {
            return d_controller.get_object();
        }

        [[nodiscard]] constexpr const typename ControlledType::object_type* operator->() const noexcept {
            return d_controller.get_object();
        }
    };

	/// brief: the class shapes a some wrapper around target object (ObjectType)
	/// note1:
	/// The wrapping around is a RAII-class (WrapperType) to so something before and after using the target object.
	/// An action launched before is launch from a constructor of a WrapperType-class instance.
	/// An action launched after is launch from a destructor of a WrapperType-class instance.
	/// note2: you can think about this class as the python's decorators.
	/// t-param: ObjectType - type of the target object for to use under the wrapper
	/// t-param: WrapperType - type of the wrapper 
    template<class ObjectType, template<class> class WrapperType>
    class execute_around {
        ObjectType d_object;

        public:
        using wrapper_type = WrapperType<ObjectType>;

        template<class... ArgsTypes>
        execute_around(ArgsTypes&&... i_args) noexcept
            : d_object{ std::forward<ArgsTypes>(i_args)... } {};

    	/// brief: returns a instance of wrapper witch gets reference to the target object as the first arguments of its constructor
        template<class... ArgsTypes>
        [[nodiscard]] wrapper_type get_wrapper(ArgsTypes&&... i_args) noexcept {
            return wrapper_type{ std::ref(d_object), std::forward<ArgsTypes>(i_args)... };
        }
    };

    template<class ObjectType>
    using sync_executor = execute_around<access_controller<ObjectType>, synchronizer>;
} // namespace parallelization
