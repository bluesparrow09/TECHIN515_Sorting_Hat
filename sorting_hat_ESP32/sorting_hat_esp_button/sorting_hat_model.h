#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class DecisionTree {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        if (x[2] <= 2.5) {
                            if (x[0] <= 2.5) {
                                if (x[1] <= 2.5) {
                                    return 0;
                                }

                                else {
                                    if (x[1] <= 3.5) {
                                        return 1;
                                    }

                                    else {
                                        return 2;
                                    }
                                }
                            }

                            else {
                                if (x[5] <= 2.5) {
                                    return 2;
                                }

                                else {
                                    if (x[4] <= 2.5) {
                                        return 1;
                                    }

                                    else {
                                        return 2;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[3] <= 2.5) {
                                if (x[1] <= 2.5) {
                                    if (x[0] <= 2.5) {
                                        return 0;
                                    }

                                    else {
                                        if (x[4] <= 2.0) {
                                            return 1;
                                        }

                                        else {
                                            return 2;
                                        }
                                    }
                                }

                                else {
                                    return 2;
                                }
                            }

                            else {
                                if (x[0] <= 2.5) {
                                    if (x[1] <= 2.5) {
                                        return 0;
                                    }

                                    else {
                                        return 3;
                                    }
                                }

                                else {
                                    return 3;
                                }
                            }
                        }
                    }

                protected:
                };
            }
        }
    }